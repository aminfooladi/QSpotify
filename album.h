#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

class Album
{
private:
    int id;
    QString name;
    int artistId;
    QString cover;

public:
    Album();
    Album(int id, QString name, int artistId, QString cover = "");

    int getId() const;
    void setId(int id);

    QString getName() const;
    void setName(const QString& name);

    int getArtistId() const;
    void setArtistId(int artistId);

    QString getCover() const;
    void setCover(const QString& cover);
};

#endif // ALBUM_H