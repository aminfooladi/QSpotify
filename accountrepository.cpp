#include "accountrepository.h"

AccountRepository::AccountRepository() {}

int AccountRepository::save(const Account &temp)
{
    return 0 ;
}

optional<Account> AccountRepository::search(int ID)
{
    Account a ;
    return a ;
}

bool AccountRepository::remove(int ID)
{
    return 0 ;
}
