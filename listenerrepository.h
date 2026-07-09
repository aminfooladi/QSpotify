#ifndef LISTENERREPOSITORY_H
#define LISTENERREPOSITORY_H

#include "accountrepository.h"

class ListenerRepository : public AccountRepository
{
public:
    ListenerRepository();

    virtual optional<Account>searchByUserName(QString userName) override ;
};

#endif // LISTENERREPOSITORY_H
