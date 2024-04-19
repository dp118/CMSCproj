/*******************************
 * File: Passenger.cpp
 * Author: Duarmienne Pineda
 * Date: 10/29/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Easy-peasy passenger file
 * for constructor and getters.
 *******************************/

#include "Passenger.h"
#include <string>
using namespace std;

//overloaded passenger constructor
Passenger::Passenger(string name, int age, string startLoc, string finalLoc) {
    m_fullName = name;
    m_age = age;
    m_startLocation = startLoc;
    m_finalDestination = finalLoc;
}

// getter for passenger's name
string Passenger::GetName() {
    return m_fullName;
}

// getter for passenger's starting location
string Passenger::GetStartLocation() {
    return m_startLocation;
}

// getter for passenger's departing location
string Passenger::GetFinalDestination() {
    return m_finalDestination;
}