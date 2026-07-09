#ifndef ALBUMREPOSITORY_H
#define ALBUMREPOSITORY_H

#include "abstractrepository.h"
#include "album.h"

#include <vector>

class AlbumRepository : public AbstractRepository<Album>
{
private:
    std::vector<Album> albums ;
public:
    AlbumRepository();

    virtual int save(const Album& temp) override ;
    virtual std::optional<Album> search(int ID) override ;
    virtual bool remove(int ID) override ;

    std::vector<Album> getAlbums(int artistID) ;
};

#endif // ALBUMREPOSITORY_H
