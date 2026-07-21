#include "playlistrepository.h"
using namespace std ;

PlaylistRepository::PlaylistRepository() {}

int PlaylistRepository::save(const Playlist &playlist)
{
    if (playlist.getId() == 0)
    {
        Playlist newPlaylist = playlist;
        newPlaylist.setId(playlists.size() + 1);
        playlists.push_back(newPlaylist);
        return newPlaylist.getId();
    }

    for (int i = 0; i < playlists.size(); i++)
    {
        if (playlists[i].getId() == playlist.getId())
        {
            playlists[i] = playlist;
            return playlists[i].getId();
        }
    }

    playlists.push_back(playlist);
    return playlist.getId();
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
    for (int i = 0; i < playlists.size(); i++)
    {
        if (playlists[i].getId() == playlistID)
        {
            playlists[i].setSongID(songID);
            return;
        }
    }
}

void PlaylistRepository::removeSong(int playlistID, int songID)
{
    for (int i = 0; i < playlists.size(); i++)
    {
        if (playlists[i].getId() == playlistID)
        {
            playlists[i].removeSongID(songID);
            return;
        }
    }
}

std::vector<Playlist> PlaylistRepository::getAllPlaylists()
{
    return this->playlists ;
}

std::vector<Playlist> PlaylistRepository::getByWordOrWordsOfName(QString wordOrWords)
{
    vector<Playlist> result;
    for ( int i=0 ; i<playlists.size() ; i++ )
    {
        if(playlists[i].getName().startsWith(wordOrWords))
        {
            result.push_back(playlists[i]);
        }
    }
    return result;
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





