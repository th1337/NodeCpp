#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "request.h"
#include "user.h"

namespace NodeCpp
{

class Authenticator
{
public:
    Authenticator();
    
    /**
     * Authenticate the user and add it to the Request.
     * @return True if an user was authenticated, false otherwise.
     */
    virtual void Handle(Request& request) final;
    
    /**
     * According to a Request, authenticate the User.
     * If no User were authenticated, it should be an anonymous User.
     * The User has to be dynamically allocated in this method.
     * @return The User.
     */
    virtual User* AuthenticateUser(const Request& request) = 0;
};

}

#endif // AUTHENTICATOR_H
