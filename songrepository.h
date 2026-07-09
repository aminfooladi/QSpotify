#ifndef SONGREPOSITORY_H
#define SONGREPOSITORY_H

#include "abstractrepository.h"
#include "song.h"

#include <vector>

class SongRepository : public AbstractRepository<Song>
{
private:
    vector<Song> songs ;
public:
    SongRepository();

    virtual int save(const Song& temp) override ;
    virtual optional<Song> search(int ID) override ;
    virtual bool remove(int ID) override ;

    vector<Song> singleSongs(int ArtistID) ;
    vector<Song> getByArtist(int artistId);
    vector<Song> getByAlbum(int albumId);
};

#endif // SONGREPOSITORY_H
