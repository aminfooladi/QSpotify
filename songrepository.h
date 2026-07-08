#ifndef SONGREPOSITORY_H
#define SONGREPOSITORY_H

#include "abstractrepository.h"
#include "song.h"

class SongRepository : public AbstractRepository<Song>
{
public:
    SongRepository();

    virtual int save(const Song& temp) override ;
    virtual optional<Song> search(int ID) override ;
    virtual bool remove(int ID) override ;
};

#endif // SONGREPOSITORY_H
