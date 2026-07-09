#ifndef ALBUMREPOSITORY_H
#define ALBUMREPOSITORY_H

#include "abstractrepository.h"
#include "album.h"

#include <vector>

class AlbumRepository : public AbstractRepository<Album>
{
private:
    vector<Album> albums ;
public:
    AlbumRepository();

    virtual int save(const Album& temp) override ;
    virtual optional<Album> search(int ID) override ;
    virtual bool remove(int ID) override ;

    vector<Album> getAlbums(int artistID) ;
};

#endif // ALBUMREPOSITORY_H
