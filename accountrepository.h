#ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#include "abstractrepository.h"
#include "account.h"

#include <vector>

class AccountRepository : public AbstractRepository<Account>
{
private:
    std::vector<Account> accounts;
public:
    AccountRepository();

    virtual int save(const Account& temp) override ;
    virtual optional<Account> search(int ID) override ;
    virtual bool remove(int ID) override ;
};

#endif // ACCOUNTREPOSITORY_H
