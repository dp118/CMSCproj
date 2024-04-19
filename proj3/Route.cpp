/*******************************
 * File: Route.cpp
 * Author: Duarmienne Pineda
 * Date: 10/29/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: link list route created
 * for the train
 *******************************/
#include "Route.h"
#include "Stop.cpp"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

// constructor for route
Route::Route() {
    m_currentStop = nullptr;
    m_head = nullptr;
    m_tail = nullptr;
    m_totalStops = 0;
}

// destructor for route
Route::~Route() {
    Stop *temp = m_head;
    while(m_head != nullptr){
        temp = m_head->GetNextStop();
        delete m_head;
        m_head = temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_totalStops = 0;
}
// reads route file, creates new stop for each line
void Route::LoadRoute(string fileName) {
    string routeName, routeNum;
    int numStops = 30;
    ifstream routes(fileName);
    routes.is_open();
    // loop through number of stops to get info
    for(int i = 0; i < numStops; i++){
        getline(routes, routeName, ',');
        getline(routes, routeNum, '\n');
        AddStop(routeName,stoi(routeNum));
    }
    m_currentStop = m_head; // set to very first stop
    routes.close();
}

// adds a new stop at the end of route linked list
void Route::AddStop(string routeName, int routeNum) {
    if(m_head == nullptr){
        m_head = new Stop(routeName, routeNum);
        m_tail = new Stop(routeName, routeNum);
    } else {
        Stop *currStop = m_head;
        while(currStop->GetNextStop() != nullptr){
            currStop = currStop->GetNextStop();
        }
        Stop *temp = new Stop(routeName, routeNum);
        currStop->SetNextStop(temp);
        m_tail = temp;
    }
    m_totalStops ++; // add to total od stops
}

// prints information about the stops
void Route::PrintRouteDetails() {
    if(m_head->GetNextStop() == nullptr){
        // at the end of the route, cannot go further.
        cout<< "There is no next stop. ";
    } else {
        // information displayed about current stop and next stop
        cout << "The current stop is " << m_currentStop->GetName()
             << " (" <<  m_currentStop->GetNumber() << ")" << endl;
        cout << "The next stop is " << m_currentStop->GetNextStop()->GetName()
        << " (" <<  m_currentStop->GetNextStop()->GetNumber() << ")" << endl;
        }
    }

    /*
    // to test if entire linked list displays
    if (m_head == nullptr) {
        cout << "empty";
    } else {
        Stop *temp = m_head;
        for (int i = 0; i < m_totalStops; i++) {
            cout << temp->GetName() << " " << temp->GetNumber() << endl;
            temp = temp->GetNextStop();
        }
    }
}
*/

// getter for current stop
Stop *Route::GetCurrentStop() {
    return m_currentStop;
}

// setter for current stop
void Route::SetCurrentStop(Stop *currStop) {
    m_currentStop = currStop;
}

// reverses the route when you are at the end of the route
void Route::ReverseRoute() {
    if(m_currentStop->GetNextStop() == nullptr){
        // when you are at the last stop
        Route *reverseRoute = new Route;
        Stop *current = m_head; // the current stop
        while(current != nullptr){ // while the current stop is not empty
            if(reverseRoute->m_head == nullptr) {
                reverseRoute->m_head = new Stop(current->GetName(),current->GetNumber());
                reverseRoute->m_tail = new Stop(current->GetName(),current->GetNumber());
            } else {

                Stop *temp = reverseRoute->m_head; // creates a temp for the reverse route
                // overwrites current link list
                reverseRoute->m_head = new Stop(current->GetName(),current->GetNumber());
                reverseRoute->m_head->SetNextStop(temp);
                // replaces information from reverse route to the current link list
                Stop *position = reverseRoute->m_head;
                while(position->GetNextStop() != nullptr){
                    position = position->GetNextStop();
                }
                reverseRoute->m_tail = position;

            }
            current = current->GetNextStop();

        }
        // m_head and m_tail changed to the info from reverse route
        m_head = reverseRoute->m_head;
        m_tail = reverseRoute->m_tail;
        SetCurrentStop(m_head);
        cout << "Train successfully turned around." << endl;
    }
    else
        cout << "You are not at the last stop, you cannot turn the train around." << endl;
}
