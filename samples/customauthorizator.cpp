#include "customauthorizator.h"
#include "customuser.h"
#include <typeinfo>

CustomAuthorizator::CustomAuthorizator() : Authorizator()
{
    
}

bool CustomAuthorizator::Accept(const Request& request)
{
    User* rawUser = request.GetUser();
    
    if (!rawUser->IsAnonymous())
    {
        const CustomUser* customUser = dynamic_cast<const CustomUser*>(rawUser);
        
        if (customUser != nullptr)
        {
            //Only the user whose id is 1 is accepted.
            return (customUser->GetId() == 1);
        }
        else
        {
            //Error, not a CustomUser.
            return false;
        }
    }
    
    return false;
}