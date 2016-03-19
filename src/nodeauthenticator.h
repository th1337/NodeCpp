#ifndef NODEAUTHENTICATOR_H
#define NODEAUTHENTICATOR_H

#include "request.h"
#include "tokengenerator.h"

namespace NodeCpp
{
class NodeAuthenticator
{
public:

    const string LOGIN = "login";
    const string PASSWORD = "password";
    const string TOKEN  = "token";

    NodeAuthenticator(TokenGenerator* generator);

    virtual int Handle(Request& request);

protected :

    virtual int AuthenticateUser(string login, string password) = 0;
    virtual int AuthenticateToken(string token) = 0;
    virtual int StoreToken(string token, int id) = 0;
    virtual string GenerateToken(int id);

private :
    TokenGenerator* tokenGenerator;
};
}
#endif // NODEAUTHENTICATOR_H
