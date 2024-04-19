/*******************************
 * File: MediaPlayer.cpp
 * Author: Duarmienne Pineda
 * Date: 12/3/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: MainMenu for MediaPlayer.
 *******************************/
#include "MediaPlayer.h"

// default mediaplayer constructor
MediaPlayer::MediaPlayer() {
    string fileName;
    cout << "Enter the name of your file: ";
    cin >> fileName;
    m_mediaCatalog = {};
    m_playList = {};
    LoadCatalog(fileName);
    MainMenu();
}

// overloaded mediaplayer constructor
MediaPlayer::MediaPlayer(string filename) {
    m_mediaCatalog = {};
    m_playList = {};
    LoadCatalog(filename);
    MainMenu();
}

// mediaplayer destructor
MediaPlayer::~MediaPlayer() {
    m_mediaCatalog = {};
    m_playList = {};
}

//loads in the file of the list of songs
void MediaPlayer::LoadCatalog(string filename) {
    string title, artist, type, year, rank;
    ifstream media(filename);
    media.is_open();
    for(int i = 0; i < 6300; i++){
        getline(media,title,';');
        getline(media,artist,';');
        getline(media,type,';');
        getline(media,year,';');
        getline(media,rank, '\n');
        Media *newMedia = new Media(title, artist, type, stoi(year), stoi(rank));
        m_mediaCatalog.push_back(newMedia);
        delete newMedia;
    }
    media.close();
}

//main menu for for mediaplayer
void MediaPlayer::MainMenu() {
    cout << m_mediaCatalog.size() << " media files loaded." << endl;
    int choice;
    do {
    cout << "What would you like to do?" << endl << "1. Display Media by Type and Year" << endl
             << "2. Add Media to Playlist" << endl << "3. Display Playlist" << endl
             << "4. Sort Playlist" << endl << "5. Quit" << endl;
    cin >> choice;
    while (choice > 5 or choice < 1) {
        cout << "That is a not a valid choice, enter 1-5" << endl;
        cin >> choice;
    } 
        switch (choice) {
            case 1:
                DisplayMedia();
                break;
            case 2:
                AddMedia();
                break;
            case 3:
                DisplayPlaylist();
                break;
            case 4:
                SortPlaylist();
                break;
            default:
                cout << "Thank you for using the UMBC Media Player" << endl;
                break;
        }
    }while (choice != 5);
}

// displays media
int MediaPlayer::DisplayMedia() {
    int year;
    cout << "Enter a year from 1958 - 2020: ";
    cin >> year;
    while (year > MAX_YEAR or year < MIN_YEAR) {
        cout << "That is a not a valid choice, enter a year from 1958 - 2020: ";
        cin >> year;
    }

    return 0;
}

//add media to playlist
void MediaPlayer::AddMedia() {
    if(m_playList.IsEmpty()){
        cout << "The playlist is empty" << endl;
    }
    else{
        DisplayPlaylist();
    }
    cout << "Choose what media you would like to add to the playlist." << endl
    << "Which media type do you want to display? (1958-2020)";

}

// display the existing playlist
void MediaPlayer::DisplayPlaylist() {

}

// sorts the playlist
void MediaPlayer::SortPlaylist() {
    if(m_playList.IsEmpty()){
        cout << "The playlist is empty" << endl;
    }
    else {
        m_playList.Sort();
    };

}

