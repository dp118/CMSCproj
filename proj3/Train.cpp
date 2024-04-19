/*******************************
 * File: Train.cpp
 * Author: Duarmienne Pineda
 * Date: 10/29/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: train link list created
 * by making cars onto the train
 * and displays info
 *******************************/

#include "Train.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

// overloaded train constructor, really wishing m_tail was available to use
Train::Train(Route *route) {
    m_route = route;
    Car *newCar = new Car(0,1);
    m_head = newCar;
    m_totalCars = 1;
}

// train destructor, make all the passengers disappear
Train::~Train() {
    Car *temp = m_head;
    while(m_head != nullptr){
        temp = m_head->m_next;
        delete m_head;
        m_head = temp;
    }
    m_route = nullptr;
    m_head = nullptr;
    m_totalCars = 0;
}

// add at end link list function, but pertaining to a car
void Train::AddCar() {
    if(m_head == nullptr){
        cout << "There is no train." << endl;
    } else {
        Car *newCar = m_head;
        while(newCar->m_next != nullptr){
            newCar = newCar->m_next;
        }
        newCar->m_next = new Car(0,m_totalCars + 1);
        ++m_totalCars; // add number of cars
    }
}

// Name: RemoveCar(Car*)
// Desc - Removes a car from either the beginning, middle or end of train linked list
// Preconditions - Train exists
// Postconditions - Removes specific car (including passengers)
// UNUSED - 3 Bonus Pts for completing if rest of project is completed
void Train::RemoveCar(Car *) {
    // brain hurt too much with link lists, pls no
}

// distplays informations about number of cars, number of passengers, and the route details
void Train::TrainStatus() {
    // thinking you had to get the total ;<
    Car *temp = m_head;
    if(temp->m_passengers.size() == 0)
        cout << "There are no passengers on the train." << endl;
    else{
        cout << "The total number of cars on the train is " << m_totalCars << "." << endl;
        // loop through number of cars and gets info
        for (int i = 0; i < m_totalCars; i++){
            cout << "Car " << temp->m_carNumber << " has " << temp->m_capacity << " passengers." << endl;
            temp = temp->m_next;
        }
    }
    m_route->PrintRouteDetails(); // calls function to display details about route
}

// loads passenger file and creates a passenger if meets conditional
void Train::LoadPassengers(string passName) {
    string  fullName, fName, lName, age, startLoc, endLoc;
    int newPass = 0;
    int numPassengers = 300;
    ifstream passengers(passName);
    passengers.is_open();
    for(int i = 0; i < numPassengers; i++){
        getline(passengers, fName, ',');
        getline(passengers, lName, ',');
        fullName = (fName + " " + lName);
        getline(passengers, age, ',');
        getline(passengers, startLoc, ',');
        getline(passengers, endLoc, '\n');
        // constantly putting my files in the wrong folder, brain go brrrr
        // if the starting location is the same as the current stop
        if(startLoc == m_route->GetCurrentStop()->GetName()){
            // create passenger with all their details
            Passenger *person = new Passenger(fullName, stoi(age), startLoc, endLoc);
            BoardPassenger(person);
            newPass ++;
        }
    }
    passengers.close();
    cout << newPass << " passengers were boarded." << endl;
}

// boards the passengers onto the train, may need to add new car
void Train::BoardPassenger(Passenger *newPassenger) {
    Car *temp = m_head;
    for (int i = 1; i <= m_totalCars; i++) {
        // checks if current car is full, isn't last car
        if (temp->m_capacity >= CAR_CAPACITY and temp->m_next != nullptr)
            temp = temp->m_next;
        // checks if current car is full, is last car
        else if (temp->m_capacity >= CAR_CAPACITY and temp->m_next == nullptr) {
            //cout << "butts";
            AddCar(); // creates new car
            cout << m_totalCars;
            temp = temp->m_next;
            // adds passenger to new car
            cout << newPassenger->GetName() << " boards the train and is headed to "
                 << newPassenger->GetFinalDestination() << "." << endl;
            temp->AddPassenger(newPassenger);
            ++ temp->m_capacity;
            i = m_totalCars;
        }
        else{
            // adds person to the next available car
            cout << newPassenger->GetName() << " boards the train and is headed to "
                 << newPassenger->GetFinalDestination() << "." << endl;
            temp->AddPassenger(newPassenger);
            ++ temp->m_capacity;
            i = m_totalCars;
        }
    }
}

// will check if the passenger is at their final destination, then they will leave
void Train::DisembarkPassengers() {
    bool leaving;
    Car *temp = m_head;
    while(temp != nullptr){
        // loops through the number of passengers
        for(unsigned int i = 0; i < temp->m_passengers.size(); i++) {
            // if the passenger's final destination is at the current stop
            if(temp->m_passengers[i]->GetFinalDestination() == m_route->GetCurrentStop()->GetName()){
                cout << temp->m_passengers[i]->GetName() << " is leaving." << endl;
                // make the passenger disappear
                temp->m_passengers.erase(temp->m_passengers.begin() + i);
                // remove passenger from existence
                delete temp->m_passengers[i];
                leaving = true; // person has left the train
                i--; // to take into account the leaving passenger
                -- temp->m_capacity;
            }
        }
        temp = temp->m_next;
    }
    if(!leaving) // boolean if no one has left at the current station
        cout << "There are no passengers leaving at this station." << endl;

}

//goes to the next stop
void Train::TravelToNextStop() {
    // cannot go forward because the next stop does not exist
    if (m_route->GetCurrentStop()->GetNextStop() == nullptr)
        cout << "You are already at the last stop." << endl;
    else{
        // goes to next stop
        m_route->SetCurrentStop(m_route->GetCurrentStop()->GetNextStop());
        cout << "You are at " << m_route->GetCurrentStop()->GetName() << endl;
    }

}

// simply put, calls reverseRoute (where all my blood, sweat, and tears were put into)
void Train::TurnTrainAround() {
    m_route->ReverseRoute();
}

// checks if train is full
bool Train::IsTrainFull() {
    Car *temp = m_head;
    while(temp != nullptr) {
        cout << temp->m_capacity;
        if(temp->m_capacity < CAR_CAPACITY){
            return false;
        }
        else{
            temp = temp->m_next;
        }
    }
    return true;
}
