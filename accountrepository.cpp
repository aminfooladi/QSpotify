#include "accountrepository.h"
using namespace std ;

AccountRepository::AccountRepository() {}

int AccountRepository::save(const Account &account)
{
    if (account.getId() == 0)
    {
        Account newAccount = account;
        newAccount.setId(accounts.size() + 1);
        accounts.push_back(newAccount);
        return newAccount.getId();
    }

    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getId() == account.getId())
        {
            accounts[i] = account;
            return accounts[i].getId();
        }
    }

    accounts.push_back(account);
    return account.getId();
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

std::optional<Account> AccountRepository::searchByUserName(QString userName)
{
    for(int i=0 ; i<accounts.size() ; i++ )
    {
        if(accounts[i].getUserName()==userName) return accounts[i] ;
    }
    return nullopt ;
}
