/*******************************
 * File: pirate.cpp
 * Author: Duarmienne Pineda
 * Date: 10/8/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Creates pirate objects to be used with pirate game,
 * where the game logic goes.
 * (good practice with private and public variables,
 * made my head turn though)
 *******************************/

#include "Pirate.h"
#include "Ship.h"

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// default pirate constructor
Pirate::Pirate() {
    m_pirateName = "Name";
    m_pirateRating = 0;
    m_pirateOrigin = "Here";
    m_pirateDesc = "Yarr I am a pirate.";
}

// overloaded pirate constructor
Pirate::Pirate(string name, int rating, string origin, string desc) {
    //cout << "building a pirate >:[" << endl; // angy
    m_pirateName = name;
    m_pirateRating = rating;
    m_pirateOrigin = origin;
    m_pirateDesc = desc;
}

// getter for pirate name
string Pirate::GetName() {
    return m_pirateName;
}

// getter for pirate rating
int Pirate::GetRating() {
    return m_pirateRating;
}

// getter for pirate origin
string Pirate::GetOrigin() {
    return m_pirateOrigin;
}

// getter for pirate description
string Pirate::GetDesc() {
    return m_pirateDesc;
}

// setter for a pirate's type of ship
void Pirate::SetCurShip(Ship curShip) {
    m_curShip = curShip;
}

// calculates the treasure gained after winning a battle
// treasure = enemy ship's cannon, max toughness, and speed divided by 3
void Pirate::CalcTreasure(Ship enemyShip) {
    int treasureEarned;
    treasureEarned = (enemyShip.m_cannon + enemyShip.m_toughness + enemyShip.m_speed) / 3;
    cout << m_pirateName << " shares " << treasureEarned << " treasure with their crew!" << endl;
    m_pirateCargo = m_pirateCargo + treasureEarned;
}

// battle! two pirates enter, one pirate leaves
// each pirate has a different rating, which determines their accuracy
void Pirate::Battle(Pirate enemyPirate, Ship enemyShip) {
    int shotsHit;
    bool didItHit, winner; // winner if either one wins
    // must have greater than 0 toughness
    if(m_curShip.m_curToughness > 0){
        winner = false;
        cout << "A naval battle of the ages commences between " << m_pirateName
            << " and " << enemyPirate.GetName() << endl;
        // keep shooting cannons at each other until one of them reaches toughness of 0
        while(!winner){
            // gets random number, if that number is less than the pirateRating,
            // then shot hits, subtracts from toughness, repeats for the amount of cannons
            //outer if-statement prevents another shot when there is already a winner
            if (m_curShip.m_curToughness > 0 and enemyShip.m_curToughness > 0) {
                shotsHit = 0; // resets the num of shots hit
                cout << m_pirateName << " fires " << m_curShip.m_cannon << " cannons!" << endl;
                // iterates through each cannon the ship has
                for (int i = 0; i < m_curShip.m_cannon; i++) {
                    // did it hit??? 1 through pirateRating is a hit
                    didItHit = (rand() % 100) < m_pirateRating;
                    if (didItHit) {
                        ++shotsHit;
                        --enemyShip.m_curToughness;
                    }
                }
                cout << shotsHit << " shots hit!" << endl;
            }
            if (enemyShip.m_curToughness > 0 and m_curShip.m_curToughness > 0) {
                shotsHit = 0;
                cout << enemyPirate.GetName() << " fires " << enemyShip.m_cannon << " cannons back!" << endl;
                for(int i = 0; i < m_curShip.m_cannon; i++) {
                    didItHit = (rand() % 100) < enemyPirate.GetRating();
                    if (didItHit) {
                        ++shotsHit;
                        --m_curShip.m_curToughness;
                    }
                }
                cout << shotsHit << " shots hit!" << endl;
            }

            // conditions when they stop fighting, one has won the battle
            // toughness is less than 1
            if(m_curShip.m_curToughness < 1){
                cout << "You lose!" << endl;
                winner = true;
                m_curShip.m_curToughness = 0;
                // lose half of your cargo
                m_pirateCargo = m_pirateCargo / 2;
                cout << "You lost " << m_pirateCargo << " treasure" << endl;
            }
            // condition if enemy wins
            if(enemyShip.m_curToughness < 1){
                cout << "You win" << endl;
                winner = true;
                // if user wins battle, get treasure
                CalcTreasure(enemyShip);}
        }
        ++ m_pirateDays; // adds a day for battling
        enemyShip.m_curToughness = enemyShip.m_toughness; // resets enemy's toughness
    }
    else {
        // cannot battle if the ship's toughness is 0
        cout << "You must repair your ship before you battle." << endl;
    }
}

// Name: RepairShip
// Desc - Repairs m_curShip and increases m_pirateDays by 1 per m_maxToughness - m_curToughness
// Preconditions - Ship damaged
// Postconditions - Repairs ship and increases days (1 day per point of damage)
void Pirate::RepairShip() {
    int daysTaken;
    // doesn't need to repair ship if toughness is at max
    if (m_curShip.m_curToughness == m_curShip.m_toughness){
        cout << "Your " << m_curShip.m_type << " is already fully repaired." << endl;
    }
    // essentially the amount of damage the ship has taken is how long it takes to fix the ship
    else if(m_curShip.m_curToughness < m_curShip.m_toughness) {
        daysTaken = (m_curShip.m_toughness - m_curShip.m_curToughness);
        cout << "It takes " << daysTaken << " days to repair your " << m_curShip.m_type << endl;
        m_pirateDays = m_pirateDays + daysTaken;
        m_curShip.m_curToughness = m_curShip.m_toughness;
    }
}

// user has the chance to flee from a ship
void Pirate::Flee(Pirate enemyPirate, Ship enemyShip) {
    cout << "You attempt to flee from " << enemyPirate.GetName() << "!" <<endl;
    ++ m_pirateDays;
    // if the user's ship is faster than the enemy, then it escapes
    if(m_curShip.m_speed > enemyShip.m_speed){
        cout << "You narrowly escape from " << enemyPirate.GetName() << endl;
    }
    else{
        // being unable to flee means you have to battle the pirate
        cout << "You were not fast enough to flee from " << enemyPirate.GetName() << endl;
        Battle(enemyPirate,enemyShip);
    }
}

// displays all the information about the pirate and their journey:
// name, rating, origin, desc, cargo, days, cargo/days, and info about m_curShip
void Pirate::DisplayScore() {
    double cargoPerDay = 0;
    // cannot divide by 0, so cargo/day set to 0
    if(m_pirateDays == 0)
        cargoPerDay = 0;
    else
        cargoPerDay = double(m_pirateCargo)/m_pirateDays;
    // pretty lil display :)
    cout << "***********************************************" << endl
        << "Name: " << m_pirateName << endl
        << "Rating: " << m_pirateRating << endl
        << "Country of Origin: " << m_pirateOrigin << endl
        << "Description: " << m_pirateDesc << endl
        << "Days sailing: " << m_pirateDays << endl
        << "Cargo Captured: "<< m_pirateCargo << endl
        << "Cargo Per Day: " << cargoPerDay << endl
        << "Ship Type: " << m_curShip.m_type << endl
        << "Ship Current Toughness: " << m_curShip.m_curToughness << endl
        << "Ship Max Toughness: " << m_curShip.m_toughness << endl
        << "Ship Speed: " << m_curShip.m_speed << endl
        << "***********************************************" << endl;
}

