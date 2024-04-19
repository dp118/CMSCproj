/*******************************
 * File: Plant.cpp
 * Author: Duarmienne Pineda
 * Date: 11/12/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Plant class along with child classes
 *******************************/
#include "Plant.h"
#include "Sunflower.h"
#include "Chomper.h"
#include "Peashooter.h"
#include "Game.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// constructor and destructor for plant
Plant::Plant() {SetName("Plant");SetHealth(PLANT_HEALTH);}
Plant::Plant(string name, int hp) : Entity(){ SetName(name);SetHealth(hp);}
Plant::~Plant() {SetName(nullptr);SetHealth(0);}

// all the plants have the same regular attack
int Plant::Attack() {
    int damage = rand() % 6 + 1;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}
// but different special attacks
int Plant::SpecialAttack() {
    cout << GetName() << " does not have a special attack." << endl;
}

// constructor and destructor for Sunflower babies
Sunflower::Sunflower() {SetName("Sunflower");SetHealth(SUNFLOWER_HEALTH);}
Sunflower::Sunflower(string name, int hp): Plant(name, hp){}
Sunflower::~Sunflower() {Plant::~Plant();}
int Sunflower::SpecialAttack() {
    int damage = rand() % 8 + 1;
    cout << GetName() << " uses a high beam turret **SUNBEAM**" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}


// constructor and destructor for Chomper babies
Chomper::Chomper() {SetName("Chomper");SetHealth(CHOMPER_HEALTH);}
Chomper::Chomper(string name, int hp): Plant(name,hp){}
Chomper::~Chomper() {Plant::~Plant();}
int Chomper::SpecialAttack() {
    int damage = rand() % 12 + 2;
    cout << GetName() << " performs a sneak attack! CHOMP!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}

// constructor and destructor for Peashooter babies
Peashooter::Peashooter() {SetName("Peashooter");SetHealth(PEASHOOTER_HEALTH);}
Peashooter::Peashooter(string name, int hp): Plant(name,hp){}
Peashooter::~Peashooter() {Plant::~Plant();}
int Peashooter::SpecialAttack() {
    int damage = rand() % 12 + 3;
    cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
    cout << GetName() << " deals " << damage << " damage!" << endl;
    return damage;
}