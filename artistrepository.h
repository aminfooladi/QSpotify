#ifndef ARTISTREPOSITORY_H
#define ARTISTREPOSITORY_H

#include "accountrepository.h"

class ArtistRepository : public AccountRepository
{
public:
    ArtistRepository();

    virtual optional<Account>searchByUserName(QString userName) override ;
};

#endif // ARTISTREPOSITORY_H
