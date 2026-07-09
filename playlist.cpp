#include "playlist.h"
using namespace std ;

Playlist::Playlist() : id(0), listenerId(0) {}

Playlist::Playlist(int id, QString name, int listenerId)
    : id(id), name(name), listenerId(listenerId) {}

int Playlist::getId() const { return id; }
void Playlist::setId(int id) { this->id = id; }

QString Playlist::getName() const { return name; }
void Playlist::setName(const QString& name) { this->name = name; }

int Playlist::getListenerId() const { return listenerId; }
void Playlist::setListenerId(int listenerId) { this->listenerId = listenerId; }

vector<int> Playlist::getSongIDs() const { return songIDs; }
void Playlist::setSongIDs(vector<int> songIDs) { this->songIDs = songIDs ; }
void Playlist::setSongID(int songID) { this->songIDs.push_back(songID); }

void Playlist::removeSongID(int songID) { this->songIDs.erase(this->songIDs.begin()+songID); }