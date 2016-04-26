#ifndef INMEMORYAUTHENTICATOR_H
#define INMEMORYAUTHENTICATOR_H

#include "nodeauthenticator.h"
#include "tokengenerator.h"

using namespace NodeCpp;
 
class InMemoryAuthenticator : public NodeAuthenticator
{
public:
    InMemoryAuthenticator(TokenGenerator* generator);
    ~InMemoryAuthenticator();

protected:
    
    /**
     * Authenticate a user with a token.
     * Return the user.
     */
    virtual User* AuthenticateToken(const string& token);
    
    /**
     * Authenticate a user with a login/password couple.
     * Return the user.
     */
    virtual User* AuthenticateUser(const string& login, const string& password);
    
    /**
     * Store an authentication token for a user.
     * This method is called when the user is logged in, to store his token.
     */
    virtual void StoreToken(const string& token, const User* user);
    
    /**
     * Remove an authentication token.
     * This method is called when the user is logged out, to remove his token.
     */
    virtual void RemoveToken(const string& token);

private:
    map<string, int> tokens_;
};

#endif // INMEMORYAUTHENTICATOR_H
