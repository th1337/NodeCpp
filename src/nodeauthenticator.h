#ifndef NODEAUTHENTICATOR_H
#define NODEAUTHENTICATOR_H

#include "request.h"
#include "tokengenerator.h"

namespace NodeCpp
{
    
class NodeAuthenticator
{
public:
    
    //Names of the request parameters.
    static const string LOGIN_PARAM;
    static const string PASSWORD_PARAM;
    static const string TOKEN_PARAM;

    NodeAuthenticator(TokenGenerator* generator);
    virtual int Handle(const Request& request);
    
    /**
     * Log the user in the NodeAuthenticator.
     * Return an authentication token for the user.
     */
    virtual string LogIn(const string& login, const string& password);

protected :
    
    /**
     * Authenticate a user with a token.
     * Return the user id.
     */
    virtual int AuthenticateToken(const string& token) = 0;
    
    /**
     * Authenticate a user with a login/password couple.
     * Return the user id.
     */
    virtual int AuthenticateUser(const string& login, const string& password) = 0;
    
    /**
     * Store an authentication token for a user.
     * This method is called when the user is logged in, to store his token.
     */
    virtual int StoreToken(const string& token, int id) = 0;

private :
    TokenGenerator* tokenGenerator_;
};

}
#endif // NODEAUTHENTICATOR_H
