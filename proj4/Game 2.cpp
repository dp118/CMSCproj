/*******************************
 * File: Game.cpp
 * Author: Duarmienne Pineda
 * Date: 11/12/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: The bulk of PvZ game, where
 * it sets all the actions of the player
 *******************************/
#include "Game.h"
#include "Room.h"

// constructor of game
Game::Game() {
    m_myPlant = nullptr;
    m_curZombie = nullptr;
    m_curRoom = 0;
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;

    string fileName;
    cout << "What is the file name?";
    cin >> fileName;
    LoadMap(fileName);
    StartGame();
}

//overloaded constructor of game
Game::Game(string file) {
    m_myPlant = nullptr;
    m_curZombie = nullptr;
    m_curRoom = 0;
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;
    LoadMap(file);
    StartGame();
}

//destructor of game
Game::~Game() {
    m_myPlant = nullptr;
    m_curZombie = nullptr;
    m_curRoom = 0;
    m_numRests = 0;
    m_numSpecial = 0;
}

void Game::LoadMap(string file) {
    // loads in the file
    string id, name, desc, north, east, south, west;
    ifstream map(file);
    map.is_open();
    do{
        getline(map, id, '|');
        getline(map, name, '|');
        getline(map, desc, '|');
        getline(map, north, '|');
        getline(map, east, '|');
        getline(map, south, '|');
        getline(map, west, '|');
        // create room object to put into vector
        Room *newRoom = new Room(stoi(id), name, desc, stoi(north), stoi(east), stoi(south), stoi(west));
        m_myMap.push_back(newRoom);
        delete newRoom;
    } while(getline(map,west,'\n'));
    map.close();
}

void Game::PlantCreation() {
    Plant *myPlant;
    int plantClass;
    string plantName;
    cout << "Plant name: " ;
    cin >> plantName;
    cout << "Select a class" << endl<< "1. Peashooter" << endl
    << "2. Chomper" << endl << "3. Sunflower" << endl << "4. No Class" << endl;
    cin >> plantClass;
    while(plantClass > 4 or plantClass < 1){
        cout << "That is a not a valid choice, enter 1-4" << endl;
        cin >> plantClass;
    }
    // creates plant depending on the class chosen
    switch(plantClass){
        case 1:
             myPlant = new Peashooter(plantName,PEASHOOTER_HEALTH);
            break;
        case 2:
            myPlant = new Chomper(plantName,CHOMPER_HEALTH);
            break;
        case 3:
            myPlant = new Sunflower(plantName,SUNFLOWER_HEALTH);
            break;
        default:
            myPlant = new Plant(plantName,PLANT_HEALTH);
            break;
    }
    m_myPlant = myPlant;
}

void Game::StartGame() {
    PlantCreation();
    RandomZombie();
    Action();
    m_myMap.at(m_curRoom)->PrintRoom();
}

void Game::Action() {
    int choice;
    do{
        cout << "What would you like to do" << endl
             << "1. Look" << endl << "2. Move" << endl << "3. Attack Zombie" << endl
             << "4. Rest" << endl << "5. Check Stats" << endl << "6. Quit" << endl;
        cin >> choice;
        while (choice > 6 or choice < 1) {
            cout << "That is a not a valid choice, enter 1-4" << endl;
            cin >> choice;
        }
        switch (choice) {
            case 1:
                break;
            case 2:
                Move();
                break;
            case 3:
                Attack();
                break;
            case 4:
                Rest();
                break;
            case 5:
                Stats();
                break;
            default:
                cout << "Goodbye!" << endl;
                break;
        }
    }while(choice != 6);
}

// determines the chance of a zombie appearing in the room
Entity *Game::RandomZombie() {
    int chanceOfZombie;
    Zombie *zombie = nullptr;
    chanceOfZombie = rand() % 4 + 1;
    if(chanceOfZombie == 1){
        zombie = new Buckethead();
    }
    else if(chanceOfZombie == 2){
        zombie = new Imp();
    }

    else if(chanceOfZombie == 3){
        zombie = new Engineer();
    }
    if (chanceOfZombie < 4){
        m_curZombie = zombie;
        cout << "There is a " << zombie->GetName() << " in the room." << endl;
    }
}

void Game::Rest() {
    if(m_curZombie != nullptr)
        cout << "You are unable to rest while there is a zombie in the room." << endl;
    else if(m_numRests == 0)
        cout << "You are out of rests." << endl;
    else {
        --m_numRests;
        m_myPlant->SetHealth(m_myPlant->GetHealth()+REST_HEAL);
    }
}

void Game::Move() {
    char nesw;
    cout << "Which direction? (N E S W)" << endl;
    cin >> nesw;
    // not one of the directions
    while(nesw != 'n' and nesw != 'N' and nesw != 'e' and nesw != 'E' and nesw != 's' and nesw != 'S' and nesw != 'w' and nesw != 'W'){
        cout << "Which direction? (N E S W)" << endl;
        cin >> nesw;
    }
    switch(nesw){
        case 'n':
        case 'N':
            // checks the direction
            if(m_myMap.at(m_curRoom)->CheckDirection(n) == -1)
                cout << "You are unable to go north." << endl;
            else
                // sets the current room to the return room id
                m_curRoom = m_myMap.at(m_curRoom)->CheckDirection(n);
            break;
        case 'e':
        case 'E':
            if(m_myMap.at(m_curRoom)->CheckDirection(e) == -1)
                cout << "You are unable to go east." << endl;
            else
                m_curRoom = m_myMap.at(m_curRoom)->CheckDirection(e);
            break;
        case 's':
        case 'S':
            if(m_myMap.at(m_curRoom)->CheckDirection(s) == -1)
                cout << "You are unable to go south." << endl;
            else
                m_curRoom = m_myMap.at(m_curRoom)->CheckDirection(s);
            break;
        case 'w':
        case 'W':
            if(m_myMap.at(m_curRoom)->CheckDirection(w) == -1)
                cout << "You are unable to go north." << endl;
            else
                m_curRoom = m_myMap.at(m_curRoom)->CheckDirection(w);
            break;
        default:
            cout << "none";
    }
    // calls a random zombie for each time you enter a room
    RandomZombie();
    m_myMap.at(m_curRoom)->PrintRoom();
    // resets specials and rests once goes to another room
    m_numSpecial = NUM_SPECIAL;
    m_numRests = NUM_RESTS;
}

// plant is able to attack a zombie if there is one in the room
void Game::Attack() {
    int attack, zombieSpecial;
    // if a zombie exists
    if(m_curZombie != nullptr){
        cout << "1. Normal Attack" << endl << "2. Special Attack" << endl;
        cin >> attack;
        while (attack != 1 and attack != 2) {
            cout << "That is not a valid choice (1-2)" << endl;
            cin >> attack;
        }
        if (attack == 2 and m_numSpecial != 0){
            // for special attack
            m_curZombie->SetHealth(m_curZombie->GetHealth() - m_myPlant->SpecialAttack());
            m_numSpecial--;
        }
        else if (attack == 2 and m_numSpecial == 0){
            cout << "You are unable to use special attack.";
            // does normal attack when cannot do special
            m_curZombie->SetHealth(m_curZombie->GetHealth() - m_myPlant->Attack());
        }
        else if (attack == 1) // normal attack
            m_curZombie->SetHealth(m_curZombie->GetHealth() - m_myPlant->Attack());

        zombieSpecial = rand() % 4 + 1;
        // determines 25% chance of special attack
        if (zombieSpecial == 1)
            m_myPlant->SetHealth(m_myPlant->GetHealth() - m_curZombie->SpecialAttack());
        else
            // normal zombie attack
            m_myPlant->SetHealth(m_myPlant->GetHealth() - m_curZombie->Attack());
        if (m_curZombie->GetHealth() < 0)
            // if the player defeats the zombie
            m_curZombie->SetHealth(0);
        // displays information of zombie and plant health after attacking
        cout << m_myPlant->GetName() << "'s health: " << m_myPlant->GetHealth() << endl;
        cout << m_curZombie->GetName() << "'s health: " << m_curZombie->GetHealth() << endl;
        // zombie is deallocated when defeated
        if (m_curZombie->GetHealth() == 0){
            cout << "You have defeated " << m_curZombie->GetName() << "!" << endl;
            m_curZombie = nullptr;
        }
    }
    else
        cout << "There is no zombie to attack." << endl;
}

// displays the stats of the plant
void Game::Stats() {
    cout << "Name: " << m_myPlant->GetName() << endl;
    cout << "HP: " << m_myPlant->GetHealth() << endl;
    cout << "Rests: " << m_numRests << endl;
    cout << "Special: " << m_numSpecial << endl;
}