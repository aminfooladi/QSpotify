#ifndef SONG_H
#define SONG_H

#include <QString>

class Song
{
private:
    int id;
    QString title;
    int releaseYear;
    QString genre;
    QString fileAddress;
    int artistId;
    int albumId;
    QString cover;

public:
    Song();
    Song(int id, QString title, int releaseYear, QString genre,
         QString fileAddress, int artistId, int albumId = 0,
         QString cover = "");

    int getId() const;
    void setId(int id);

    QString getTitle() const;
    void setTitle(const QString& title);

    int getReleaseYear() const;
    void setReleaseYear(int releaseYear);

    QString getGenre() const;
    void setGenre(const QString& genre);

    QString getFileAddress() const;
    void setFileAddress(const QString& fileAddress);

    int getArtistId() const;
    void setArtistId(int artistId);

    int getAlbumId() const;
    void setAlbumId(int albumId);

    QString getCover() const;
    void setCover(const QString& cover);
};

#endif // SONG_H