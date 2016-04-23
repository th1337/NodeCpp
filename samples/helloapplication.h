#ifndef HELLOAPPLICATION_H
#define HELLOAPPLICATION_H

#include "application.h"
#include "hellocontroller.h"
#include "sortcontroller.h"
#include "securitycontroller.h"
#include "inmemoryauthenticator.h"
#include "customauthorizator.h"
#include "hellobasicauthcontroller.h"
#include "hellobasicauthauthenticator.h"

using namespace NodeCpp;

class HelloApplication : public Application
{
public:
    HelloApplication();
    ~HelloApplication();

protected:
    void InitRoutes();

private :
    TokenGenerator token_generator_;
    InMemoryAuthenticator authenticator_;
    HelloBasicAuthAuthenticator basic_authenticator_;
    CustomAuthorizator authorizator_;

    HelloController hello_controller_;
    SortController sort_controller_;
    SecurityController security_controller_;
    HelloBasicAuthController basic_controller_;
};

#endif // HELLOAPPLICATION_H
