#ifndef NODEAUTHENTICATOR_H
#define NODEAUTHENTICATOR_H

#include "request.h"
#include "authenticator.h"
#include "tokengenerator.h"

namespace NodeCpp
{
    
class NodeAuthenticator : public Authenticator
{
public:
    
    //Names of the request parameters.
    static const string LOGIN_PARAM;
    static const string PASSWORD_PARAM;
    static const string TOKEN_PARAM;

    NodeAuthenticator(TokenGenerator* generator);
    virtual ~NodeAuthenticator();
    
    /**
     * Handle a request and try to authenticate an user.
     */
    virtual User* HandleUser(const Request& request);
    
    /**
     * Read the authentication token in the request.
     */
    virtual string ReadToken(const Request& request);
    
    /**
     * Log the user in the NodeAuthenticator.
     * Return an authentication token for the user.
     */
    virtual string LogIn(const string& login, const string& password);
    
    /**
     * Logout the user with his token.
     */
    virtual void LogOut(const string& token);

protected :
    
    /**
     * Authenticate a user with a token.
     * Return the user.
     */
    virtual User* AuthenticateToken(const string& token) = 0;
    
    /**
     * Authenticate a user with a login/password couple.
     * Return the user.
     */
    virtual User* AuthenticateUser(const string& login, const string& password) = 0;
    
    /**
     * Store an authentication token for a user.
     * This method is called when the user is logged in, to store his token.
     */
    virtual void StoreToken(const string& token, const User* user) = 0;
    
    /**
     * Remove an authentication token.
     * This method is called when the user is logged out, to remove his token.
     */
    virtual void RemoveToken(const string& token) = 0;

private :
    TokenGenerator* tokenGenerator_;
};

}
#endif // NODEAUTHENTICATOR_H
