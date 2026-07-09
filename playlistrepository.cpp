#include "playlistrepository.h"

PlaylistRepository::PlaylistRepository() {}

int PlaylistRepository::save(const Playlist &temp)
{
    return 0 ;
}

optional<Playlist> PlaylistRepository::search(int ID)
{
    for ( int i=0 ; i<playlists.size() ; i++ )
    {
        if ( playlists[i].getId()==ID ) return playlists[i] ;
    }
    return nullopt ;
}

bool PlaylistRepository::remove(int ID)
{
    for ( int i=0 ; i<playlists.size() ; i++ )
    {
        if ( playlists[i].getId()==ID )
        {
            playlists.erase(playlists.begin()+i) ;
            return true ;
        }
    }
    return false ;
}

void PlaylistRepository::insertSong(int playlistID, int songID)
{
    playlists[playlistID].setSongID(songID) ;
}

void PlaylistRepository::removeSong(int playlistID, int songID)
{
    playlists[playlistID].removeSongID(songID) ;
}

vector<Playlist> PlaylistRepository::getPlaylists(int listenerID)
{
    vector<Playlist> result;
    for ( int i=0 ; i<playlists.size() ; i++ )
    {
        if(playlists[i].getListenerId()==listenerID) result.push_back(playlists[i]) ;
    }
    return result ;
}





