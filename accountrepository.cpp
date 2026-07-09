#include "accountrepository.h"

AccountRepository::AccountRepository() {}

int AccountRepository::save(const Account &temp)
{
    return 0 ;
}

optional<Account> AccountRepository::search(int ID)
{
    for ( int i=0 ; i<accounts.size() ; i++ )
    {
        if ( accounts[i].getId()==ID ) return accounts[i] ;
    }
    return nullopt ;
}

bool AccountRepository::remove(int ID)
{
    for ( int i=0 ; i<accounts.size() ; i++ )
    {
        if ( accounts[i].getId()==ID )
        {
            accounts.erase(accounts.begin()+i) ;
            return true ;
        }
    }
    return false ;
}
