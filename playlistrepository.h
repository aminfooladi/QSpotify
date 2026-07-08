#ifndef PLAYLISTREPOSITORY_H
#define PLAYLISTREPOSITORY_H

#include "abstractrepository.h"
#include "playlist.h"

class PlaylistRepository : public AbstractRepository<Playlist>
{
public:
    PlaylistRepository();

    virtual int save(const Playlist& temp) override ;
    virtual optional<Playlist> search(int ID) override ;
    virtual bool remove(int ID) override ;
};

#endif // PLAYLISTREPOSITORY_H
