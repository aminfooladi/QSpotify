#ifndef SONGREPOSITORY_H
#define SONGREPOSITORY_H

#include "abstractrepository.h"
#include "song.h"

#include <vector>

class SongRepository : public AbstractRepository<Song>
{
private:
    std::vector<Song> songs ;
public:
    SongRepository();

    virtual int save(const Song& temp) override ;
    virtual std::optional<Song> search(int ID) override ;
    virtual bool remove(int ID) override ;

    std::vector<Song> singleSongs(int ArtistID) ;
    std::vector<Song> getByArtist(int artistID);
    std::vector<Song> getByAlbum(int albumID);
    std::vector<Song> getByPlaylist(int playlisID);
    std::vector<Song> getByLikedSongs(int listenerID) ;

    std::vector<Song> getSongs() ;
};

#endif // SONGREPOSITORY_H
