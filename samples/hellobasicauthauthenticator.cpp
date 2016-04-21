#include "hellobasicauthauthenticator.h"
#include "anonymoususer.h"
#include "hellouser.h"

using namespace NodeCpp;


HelloBasicAuthAuthenticator::HelloBasicAuthAuthenticator()
{

}

User* HelloBasicAuthAuthenticator::AcceptCredentials(string username, string password)
{

    if((username.compare("username")==0 && password.compare("password")==0) || (username.compare("th1337")==0 && password.compare("bullshitsap")==0) ){
        return new HelloUser(username, password);
    }else{
        return new AnonymousUser();
    }

}

