#ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#include "abstractrepository.h"
#include "account.h"

#include <vector>

class AccountRepository : public AbstractRepository<Account>
{
protected:
    std::vector<Account> accounts;
public:
    AccountRepository();

    virtual int save(const Account& temp) override ;
    virtual optional<Account> search(int ID) override ;
    virtual bool remove(int ID) override ;

    virtual optional<Account>searchByUserName(QString userName) = 0 ;
};

#endif // ACCOUNTREPOSITORY_H
