/*******************************
 * File: Room.cpp
 * Author: Duarmienne Pineda
 * Date: 11/12/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Room class
 *******************************/
#include "Room.h"

// overloaded room constructor
Room::Room(int id, string name, string desc, int north, int east, int south, int west) {
    m_ID = id;
    m_name = name;
    m_desc = desc;
    m_direction[0] = north;
    m_direction[1] = east;
    m_direction[2] = south;
    m_direction[3] = west;
}

// getter for name
string Room::GetName() {
    return m_name;
}

//getter for id
int Room::GetID() {
    return m_ID;
}

// getter for description
string Room::GetDesc() {
    return m_desc;
}

// inputs direction and outputs whether there is an exit in that direction
int Room::CheckDirection(char myDirection) {
    switch(myDirection){
        case 'n':
        case 'N':
            if(m_direction[0] != -1)
                return GetID();
            else
                return -1;
        case 'e':
        case 'E':
            if(m_direction[1] != -1)
                return GetID();
            else
                return -1;
        case 's':
        case 'S':
            if(m_direction[2] != -1)
                return GetID();
            else
                return -1;
        case 'w':
        case 'W':
            if(m_direction[3] != -1)
                return GetID();
            else
                return -1;
    }
    return 0;
}

// displays the room
void Room::PrintRoom() {
    cout << GetName() << endl;
    cout << GetDesc() << endl;
    for(int i = 0; i < 4; i++){
        if(CheckDirection(m_direction[i]) != -1){
            cout <<"You are able to exit through: "<< CheckDirection(m_direction[i]) << endl;
        }
    }

}

