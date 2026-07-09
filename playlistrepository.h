#ifndef PLAYLISTREPOSITORY_H
#define PLAYLISTREPOSITORY_H

#include "abstractrepository.h"
#include "playlist.h"

#include <vector>

class PlaylistRepository : public AbstractRepository<Playlist>
{
private:
    std::vector<Playlist> playlists ;
public:
    PlaylistRepository();

    virtual int save(const Playlist& temp) override ;
    virtual std::optional<Playlist> search(int ID) override ;
    virtual bool remove(int ID) override ;

    void insertSong(int playlistID , int songID) ;
    void removeSong(int playlistID , int songID) ;
    std::vector<Playlist> getPlaylists(int listenerID) ;
};

#endif // PLAYLISTREPOSITORY_H
