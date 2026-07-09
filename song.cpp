#include "song.h"
using namespace std ;

Song::Song() : id(0), releaseYear(0), artistId(0), albumId(0) {}

Song::Song(int id, QString title, int releaseYear, QString genre,
           QString fileAddress, int artistId, int albumId, QString cover)
    : id(id), title(title), releaseYear(releaseYear), genre(genre),
    fileAddress(fileAddress), artistId(artistId), albumId(albumId),
    cover(cover) {}

int Song::getId() const { return id; }
void Song::setId(int id) { this->id = id; }

QString Song::getTitle() const { return title; }
void Song::setTitle(const QString& title) { this->title = title; }

int Song::getReleaseYear() const { return releaseYear; }
void Song::setReleaseYear(int releaseYear) { this->releaseYear = releaseYear; }

QString Song::getGenre() const { return genre; }
void Song::setGenre(const QString& genre) { this->genre = genre; }

QString Song::getFileAddress() const { return fileAddress; }
void Song::setFileAddress(const QString& fileAddress) { this->fileAddress = fileAddress; }

int Song::getArtistId() const { return artistId; }
void Song::setArtistId(int artistId) { this->artistId = artistId; }

int Song::getAlbumId() const { return albumId; }
void Song::setAlbumId(int albumId) { this->albumId = albumId; }

QString Song::getCover() const { return cover; }
void Song::setCover(const QString& cover) { this->cover = cover; }