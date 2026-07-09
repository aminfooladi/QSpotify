#include "listenerrepository.h"

ListenerRepository::ListenerRepository() {}

optional<Account> ListenerRepository::searchByUserName(QString userName)
{
    for(int i=0 ; i<accounts.size() ; i++ )
    {
        if(accounts[i].getRole()==Role::Listener && accounts[i].getUserName()==userName) return accounts[i] ;
    }
    return nullopt ;
}
