/*******************************
 * File: Media.cpp
 * Author: Duarmienne Pineda
 * Date: 12/3/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description: Setters and Getters for Media
 *******************************/

#include "Media.h"

// default constructor for media
Media::Media() {
    m_title = "Untitled";
    m_artist = "Rex Orange County";
    m_type = "music";
    m_year = 2017;
    m_rank = 1;
    // from my #1 song off 2020 Spotify Wrapped
}

// overloaded constructor for media
Media::Media(string title, string artist, string type, int year, int rank) {
    m_title = title;
    m_artist = artist;
    m_type = type;
    m_year = year;
    m_rank = rank;
}

// getter for title
string Media::GetTitle() const {
    return m_title;
}

// getter for artist
string Media::GetArtist() const {
    return m_artist;
}

// getter for type
string Media::GetType() const {
    return m_type;
}

// getter for year
int Media::GetYear() const {
    return m_year;
}

// getter for rank
int Media::GetRank() const {
    return m_rank;
}

// setter for title
void Media::SetTitle(string title) {
    m_title = title;
}

// setter for artist
void Media::SetArtist(string artist) {
    m_artist = artist;
}

// setter for type
void Media::SetType(string type) {
    m_type = type;
}

// setter for year
void Media::SetYear(int year) {
    m_year = year;
}

// setter for rank
void Media::SetRank(int rank) {
    m_rank = rank;
}

ostream &operator<<(ostream &out, Media &m) {
    return out;
}

// boolean to compare the years
bool Media::operator<(const Media &m) {
    if(m.GetYear()<GetYear())
        return true;
    return false;
}

