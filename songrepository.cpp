#include "songrepository.h"
using namespace std ;

SongRepository::SongRepository() {}

int SongRepository::save(const Song &song)
{
    if (song.getId() == 0)
    {
        Song newSong = song;
        newSong.setId(songs.size() + 1);
        songs.push_back(newSong);
        return newSong.getId();
    }

    for (int i = 0; i < songs.size(); i++)
    {
        if (songs[i].getId() == song.getId())
        {
            songs[i] = song;
            return songs[i].getId();
        }
    }

    songs.push_back(song);
    return song.getId();
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

int SongRepository::serchSongByName(QString name)
{
    for ( int i=0 ; i<this->songs.size() ; i++ )
    {
        if ( songs[i].getTitle()==name )
        {
            return songs[i].getId() ;
        }
    }
    return 0 ;
}

int SongRepository::serchSongByFileAddress(QString address)
{
    for ( int i=0 ; i<this->songs.size() ; i++ )
    {
        if ( songs[i].getFileAddress()==address )
        {
            return songs[i].getId() ;
        }
    }
    return 0 ;
}

std::vector<Song> SongRepository::getSongs()
{
    return this->songs ;
}

std::vector<Song> SongRepository::getByWordOrWordsOfName(QString wordOrWords)
{
    vector<Song> result;
    for ( int i=0 ; i<songs.size() ; i++ )
    {
        if(songs[i].getTitle().startsWith(wordOrWords))
        {
            result.push_back(songs[i]);
        }
    }
    return result;
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

