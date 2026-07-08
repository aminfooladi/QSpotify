#ifndef ALBUMREPOSITORY_H
#define ALBUMREPOSITORY_H

#include "abstractrepository.h"
#include "album.h"

class AlbumRepository : public AbstractRepository<Album>
{
public:
    AlbumRepository();

    virtual int save(const Album& temp) override ;
    virtual optional<Album> search(int ID) override ;
    virtual bool remove(int ID) override ;
};

#endif // ALBUMREPOSITORY_H
