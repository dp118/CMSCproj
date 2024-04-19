/*******************************
 * File: Entity.cpp
 * Author: Duarmienne Pineda
 * Date: 11/12/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Entity class
 *******************************/

#include "Entity.h"
// entity constructor
Entity::Entity() {
    m_name = "Entity";
    m_health = 0;
}

//overloaded entity constructor
Entity::Entity(string name, int health) {
    SetName(name);
    SetHealth(health);
}

// entity destructor
Entity::~Entity() {
    m_name = nullptr;
    m_health = 0;
}

//getter for name
string Entity::GetName() {
    return m_name;
}

// getter for health
int Entity::GetHealth() {
    return m_health;
}

//setter for name
void Entity::SetName(string name) {
    m_name = name;
}

// setter for health
void Entity::SetHealth(int health) {
    m_health = health;
}

// uhhhhh
ostream &operator<<(ostream &, Entity &) {
}
