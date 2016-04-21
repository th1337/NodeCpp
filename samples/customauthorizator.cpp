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
        try
        {
            const CustomUser* customUser = dynamic_cast<const CustomUser*>(rawUser);
            
            //Only the user whose id is 1 is accepted.
            return (customUser->GetId() == 1);
        }
        catch (bad_cast& bc)
        {
            //Error, not a CustomUser.
            return false;
        }
    }
    
    return false;
}