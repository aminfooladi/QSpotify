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
    vector<Song> getByArtist(int artistID);
    vector<Song> getByAlbum(int albumID);
    vector<Song> getByPlaylist(int playlisID);
    vector<Song> getByLikedSongs(int listenerID) ;
};

#endif // SONGREPOSITORY_H
