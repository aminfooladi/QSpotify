#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <vector>
using namespace std;

class Playlist
{
private:
    int id;
    QString name;
    int listenerId;
    vector<int> songIDs ;

public:
    Playlist();
    Playlist(int id, QString name, int listenerId);

    int getId() const;
    void setId(int id);

    QString getName() const;
    void setName(const QString& name);

    int getListenerId() const;
    void setListenerId(int listenerId);

    vector<int> getSongIDs() const;
    void setSongIDs(vector<int> songIDs);
    void setSongID(int songID);

    void removeSongID(int songIDs) ;
};

#endif // PLAYLIST_H