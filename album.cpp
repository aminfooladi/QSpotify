#include "album.h"

Album::Album() : id(0), artistId(0) {}

Album::Album(int id, QString name, int artistId, QString cover)
    : id(id), name(name), artistId(artistId), cover(cover) {}

int Album::getId() const { return id; }
void Album::setId(int id) { this->id = id; }

QString Album::getName() const { return name; }
void Album::setName(const QString& name) { this->name = name; }

int Album::getArtistId() const { return artistId; }
void Album::setArtistId(int artistId) { this->artistId = artistId; }

QString Album::getCover() const { return cover; }
void Album::setCover(const QString& cover) { this->cover = cover; }