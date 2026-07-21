#ifndef DATABASE_H
#define DATABASE_H

#include "accountrepository.h"
#include "albumrepository.h"
#include "songrepository.h"
#include "playlistrepository.h"

class Database
{
public:
    AccountRepository accountRepo ;
    AlbumRepository albumRepo ;
    SongRepository songRepo ;
    PlaylistRepository playlistRepo ;

    Account userAccount;

    Database();

    void saveAll();
    void loadAll();
};

#endif // DATABASE_H
