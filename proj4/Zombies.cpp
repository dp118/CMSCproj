/*******************************
 * File: Zombiw.cpp
 * Author: Duarmienne Pineda
 * Date: 11/12/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Zombie class along with child classes
 *******************************/
#include "Zombie.h"
#include "Buckethead.h"
#include "Imp.h"
#include "Engineer.h"
#include "Game.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// constructor and overloaded constructor for zombie
Zombie::Zombie() {SetName("Zombie");SetHealth(0);}
Zombie::Zombie(string name, int hp) : Entity(){ SetName(name); SetHealth(hp);}
// normal zombie attack does one damage
int Zombie::Attack() {
    int damage = 1;
    cout << GetName() << " deals " << damage << " point of damage!" << endl;
    return damage;
}

// constructor and overloaded constructor for buckethead zombie boys
Buckethead::Buckethead() {SetName("Buckethead");SetHealth(BUCKETHEAD_HEALTH);}
Buckethead::Buckethead(string name, int hp) : Zombie(name, hp){}
int Buckethead::SpecialAttack() {
    int damage = 1;
    cout << GetName() << " throws its bucket at you!" << endl;
    cout << GetName() << " deals " << damage << " point of damage!" << endl;
    return damage;
}

// constructor and overloaded constructor for imp zombie boys
Imp::Imp() {SetName("Imp");SetHealth(IMP_HEALTH);}
Imp::Imp(string name, int hp) : Zombie(name, hp){}
int Imp::SpecialAttack() {
    int damage = 4;
    cout << GetName() << " blasts you with their Impkata attack!" << endl;
    cout << GetName() << " deals " << damage << " point of damage!" << endl;
    return damage;
}

// constructor and overloaded constructor for engineer zombie boys
Engineer::Engineer() {SetName("Engineer");SetHealth(ENGINEER_HEALTH);}
Engineer::Engineer(string name, int hp) : Zombie(name, hp){}
int Engineer::SpecialAttack() {
    int damage = 2;
    cout << GetName() << " blasts you with their steam blaster!" << endl;
    cout << GetName() << " deals " << damage << " point of damage!" << endl;
    return damage;
}