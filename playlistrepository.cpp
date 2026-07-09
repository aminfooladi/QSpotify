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

