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
    virtual std::optional<Account> search(int ID) override ;
    virtual bool remove(int ID) override ;

    virtual std::optional<Account>searchByUserName(QString userName) ;
};

#endif // ACCOUNTREPOSITORY_H
