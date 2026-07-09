#ifndef ARTISTREPOSITORY_H
#define ARTISTREPOSITORY_H

#include "accountrepository.h"

class ArtistRepository : public AccountRepository
{
public:
    ArtistRepository();

    virtual std::optional<Account>searchByUserName(QString userName) override ;
};

#endif // ARTISTREPOSITORY_H
