#ifndef BASICAUTHENTICATOR_H
#define BASICAUTHENTICATOR_H

#include "authenticator.h"

namespace NodeCpp
{

class BasicAuthenticator : public Authenticator
{
public:
    const string PREFIX = "Basic";
    const string AUTHORIZATION = "Authorization";


    BasicAuthenticator();

    /**
     * According to a Request, authenticate the User.
     * If no User were authenticated, it should be an anonymous User.
     * The User has to be dynamically allocated in this method.
     * @return The User.
     */
    virtual User* HandleUser(const Request& request) final;


    /**
     * According to a Request, authenticate the User.
     * If no User were authenticated, it should be an anonymous User.
     * The User has to be dynamically allocated in this method.
     * @return The User.
     */
    virtual User* AcceptCredentials(string username, string password) = 0;


};

}
#endif // BASICAUTHENTICATOR_H
