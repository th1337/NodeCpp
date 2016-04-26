#ifndef HELLOBASICAUTHAUTHENTICATOR_H
#define HELLOBASICAUTHAUTHENTICATOR_H

#include "basicauthenticator.h"

using namespace NodeCpp;

class HelloBasicAuthAuthenticator : public BasicAuthenticator
{
public:
    HelloBasicAuthAuthenticator();

    /**
     * According to a Request, authenticate the User.
     * If no User were authenticated, it should be an anonymous User.
     * The User has to be dynamically allocated in this method.
     * @return The User.
     */
    virtual User* AcceptCredentials(string username, string password);

};

#endif // HELLOBASICAUTHAUTHENTICATOR_H
