#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "request.h"
#include "tokengenerator.h"

namespace NodeCpp
{
class Authenticator
{
public:

    const string LOGIN = "login";
    const string PASSWORD = "password";
    const string TOKEN  = "token";

    Authenticator(TokenGenerator* generator);

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
#endif // AUTHENTICATOR_H
