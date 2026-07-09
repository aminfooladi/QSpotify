#include "songrepository.h"
using namespace std ;

SongRepository::SongRepository() {}

int SongRepository::save(const Song &temp)
{
    return 0 ;
}

optional<Song> SongRepository::search(int ID)
{
    for ( int i=0 ; i<songs.size() ; i++ )
    {
        if ( songs[i].getId()==ID ) return songs[i] ;
    }
    return nullopt ;
}

bool SongRepository::remove(int ID)
{
    for ( int i=0 ; i<songs.size() ; i++ )
    {
        if ( songs[i].getId()==ID )
        {
            songs.erase(songs.begin()+i) ;
            return true ;
        }
    }
    return false ;
}

vector<Song> SongRepository::singleSongs(int ArtistID)
{
    vector<Song> singles ;
    for ( int i=0 ; i<songs.size() ; i++ )
    {
        if (songs[i].getArtistId()==ArtistID && songs[i].getAlbumId()==0 ) singles.push_back(songs[i]) ;
    }
    return singles ;
}

vector<Song> SongRepository::getByArtist(int artistID)
{
    vector<Song> result;
    for (int i = 0; i < songs.size(); i++)
    {
        if (songs[i].getArtistId() == artistID)
        {
            result.push_back(songs[i]);
        }
    }
    return result;
}

vector<Song> SongRepository::getByAlbum(int albumID)
{
    vector<Song> result;
    for (int i = 0; i < songs.size(); i++)
    {
        if (songs[i].getAlbumId() == albumID)
        {
            result.push_back(songs[i]);
        }
    }
    return result;
}

vector<Song> SongRepository::getByPlaylist(int playlistID)
{
    vector<Song> result;

    return result;
}

vector<Song> SongRepository::getByLikedSongs(int listenerID)
{
    vector<Song> result;

    return result;
}

