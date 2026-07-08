#include "playlist.h"

Playlist::Playlist() : id(0), listenerId(0) {}

Playlist::Playlist(int id, QString name, int listenerId)
    : id(id), name(name), listenerId(listenerId) {}

int Playlist::getId() const { return id; }
void Playlist::setId(int id) { this->id = id; }

QString Playlist::getName() const { return name; }
void Playlist::setName(const QString& name) { this->name = name; }

int Playlist::getListenerId() const { return listenerId; }
void Playlist::setListenerId(int listenerId) { this->listenerId = listenerId; }