#include "artistrepository.h"
using namespace std ;

ArtistRepository::ArtistRepository() {}

optional<Account> ArtistRepository::searchByUserName(QString userName)
{
    for(int i=0 ; i<accounts.size() ; i++ )
    {
        if(accounts[i].getRole()==Role::Artist && accounts[i].getUserName()==userName) return accounts[i] ;
    }
    return nullopt ;
}
