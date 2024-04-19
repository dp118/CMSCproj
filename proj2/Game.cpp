/*******************************
 * File: game.cpp
 * Author: Duarmienne Pineda
 * Date: 10/8/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Creates a pirate game where you can
 * battle enemy pirates and steal their loot.
 * (struggling to start but i got it :))
 *******************************/

#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// calls the starting functions and loads in the game
Game::Game() {
    // displays the title
    GameTitle();
    // loads the ships and pirates
    LoadShips();
    LoadPirates();
}

// takes the info from the text file of ships
// create ship structs then placed into m_ships
void Game::LoadShips() {
    string shipType, shipDesc, shipCannons, shipToughness, shipSpeed;
    ifstream ships(PROJ2_SHIPS);
    ships.is_open();
    // gets ship values from each line of the file and assigns into usable variables
    for(int i = 0; i < MAX_SHIPS; i++ ) {
        getline(ships, shipType, ',');
        getline(ships, shipCannons, ',');
        getline(ships, shipToughness, ',');
        getline(ships, shipSpeed, ',');
        getline(ships, shipDesc, '\n');
        Ship Ship(shipType,stoi(shipCannons), stoi(shipToughness), stoi(shipSpeed), shipDesc);
        m_ships[i] = Ship;
    }
    ships.close();
    cout << MAX_SHIPS << " ships loaded." << endl;
}

// loads in all the pirates from the file as objects
// placed into m_allPirates
void Game::LoadPirates() {
    string pirateName, pirateRating, pirateOrigin, pirateDesc;
    ifstream pirates(PROJ2_PIRATES);
    pirates.is_open();
    // loopity loops through all pirates
    for(int i = 0; i < MAX_PIRATES; i++) {
        // getline: gets info from one line of file, sets  as a variable, stops reading a deliminator
        getline(pirates, pirateName, ',');
        getline(pirates, pirateRating, ',');
        getline(pirates, pirateOrigin, ',');
        getline(pirates, pirateDesc, '\n');
        Pirate Pirate(pirateName,stoi(pirateRating), pirateOrigin, pirateDesc);
        m_allPirates[i] = Pirate;
    }
    pirates.close();
    cout << MAX_PIRATES << " pirates loaded."  << endl;
}

// user is assigned a random pirate and ship
// calls the main menu
void Game::StartGame() {
    int randPirate, randShip;
    randPirate = rand() % MAX_PIRATES;
    randShip = rand() % MAX_SHIPS;
    m_myPirate = m_allPirates[randPirate];
    m_myPirate.SetCurShip(m_ships[randShip]);
    //cout << m_myPirate.GetName();
    //cout << m_ships[randShip].m_type;
    // displays the user's pirate and ship
    cout << "Congratulations! " << m_myPirate.GetName()  << " is now available to plunder!" << endl
        << m_myPirate.GetName() << " is aboard a " << m_ships[randShip].m_type << "." << endl;
    MainMenu();
}

// displays the menu and provides user with some choices
int Game::MainMenu() {
    bool mainMenu = true;
    int choice = 0;
    // to keep repeating the mainMenu
    while(mainMenu){
        cout << "What would you like to do?" << endl
            << "1. Search for Treasure" << endl
            << "2. Repair Ship" << endl
            << "3. See Score"  << endl
            << "4. Retire" << endl;
        // prompts user with choice
        cin >> choice;
        while(choice > 4 or choice < 1) {
            cout << "Enter a number 1-4." << endl;
            cin >> choice;
        }
        if(choice == 1)
            // looks for an opponent
            SearchTreasure();
        else if(choice == 2)
            // fixes ship if needed
            m_myPirate.RepairShip();
        else if(choice == 3)
            // shows score
            m_myPirate.DisplayScore();
        else{
            // the end of game
            m_myPirate.DisplayScore();
            // stops loop
            mainMenu = false;
        }
    }
    cout << m_myPirate.GetName() << " sails off into retirement." << endl
        << "Thanks for playing Pirates!" << endl;
    return 0;
}

// randomly creates an enemy pirate and their ship
// can either choose fight or flight
void Game::SearchTreasure() {
    int choice;
    int randEnemyPirate, randEnemyShip;
    // creates enemy pirate to battle
    Pirate enemyPirate;
    Ship enemyShip;
    // chooses random number in range of the max, determines the pirate
    randEnemyPirate = rand() % MAX_PIRATES;
    enemyPirate = m_allPirates[randEnemyPirate];
    // determines ship
    randEnemyShip = rand() % MAX_SHIPS;
    // setting enemy's pirate and ship
    enemyPirate.SetCurShip(m_ships[randEnemyShip]);
    enemyShip = m_ships[randEnemyShip];
    cout << "You scan the horizon for prospective targets..." << endl
        << "Off in the distance, you see " << enemyPirate.GetName()
            << " on a " << enemyShip.m_type <<"!" << endl;
    // displays options and then prompts user
    cout << "What would you like to do?" << endl
        << "1. Attack " << enemyPirate.GetName() << endl
        << "2. Attempt to flee from " << enemyPirate.GetName() << endl;
    cin >> choice;
    while(choice > 2 or choice < 1){
        cout << "Enter a number 1-2." << endl;
        cin >> choice;
    }
    if(choice == 1){
        // user battles enemy
        m_myPirate.Battle(enemyPirate,enemyShip);
    }
    else {
        // user can try to escape
        m_myPirate.Flee(enemyPirate,enemyShip);
    }
}