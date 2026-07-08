#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>

class Playlist
{
private:
    int id;
    QString name;
    int listenerId;

public:
    Playlist();
    Playlist(int id, QString name, int listenerId);

    int getId() const;
    void setId(int id);

    QString getName() const;
    void setName(const QString& name);

    int getListenerId() const;
    void setListenerId(int listenerId);
};

#endif // PLAYLIST_H