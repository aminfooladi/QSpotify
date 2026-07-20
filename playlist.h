#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <vector>

class Playlist
{
private:
    int id;
    QString name;
    int listenerId;
    std::vector<int> songIDs ;
    QString cover;

public:
    Playlist();
    Playlist(int id, QString name, int listenerId);

    int getId() const;
    void setId(int id);

    QString getName() const;
    void setName(const QString& name);

    int getListenerId() const;
    void setListenerId(int listenerId);

    std::vector<int> getSongIDs() const;
    void setSongIDs(std::vector<int> songIDs);
    void setSongID(int songID);

    QString getCover() const;
    void setCover(const QString& cover);

    void removeSongID(int songIDs) ;
};

#endif // PLAYLIST_H