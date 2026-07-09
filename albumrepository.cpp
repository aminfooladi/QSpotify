#include "albumrepository.h"
using namespace std ;

AlbumRepository::AlbumRepository() {}

int AlbumRepository::save(const Album &temp)
{
    return 0 ;
}

optional<Album> AlbumRepository::search(int ID)
{
    for ( int i=0 ; i<albums.size() ; i++ )
    {
        if ( albums[i].getId()==ID ) return albums[i] ;
    }
    return nullopt ;
}

bool AlbumRepository::remove(int ID)
{
    for ( int i=0 ; i<albums.size() ; i++ )
    {
        if ( albums[i].getId()==ID )
        {
            albums.erase(albums.begin()+i) ;
            return true ;
        }
    }
    return false ;
}

vector<Album> AlbumRepository::getAlbums(int artistID)
{
    vector<Album> result ;
    for ( int i=0 ; i<albums.size() ; i++ )
    {
        if(albums[i].getArtistId()==artistID) result.push_back(albums[i]) ;
    }
    return result;
}
