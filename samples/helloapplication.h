#ifndef HELLOAPPLICATION_H
#define HELLOAPPLICATION_H

#include "application.h"
#include "hellocontroller.h"
#include "sortcontroller.h"
#include "securitycontroller.h"
#include "inmemoryauthenticator.h"
#include "customauthorizator.h"

using namespace NodeCpp;

class HelloApplication : public Application
{
public:
    HelloApplication();
    ~HelloApplication();
    
    static ostream* debug_console;

protected:
    void InitRoutes();

private :
    TokenGenerator token_generator_;
    InMemoryAuthenticator authenticator_;
    CustomAuthorizator authorizator_;

    HelloController hello_controller_;
    SortController sort_controller_;
    SecurityController security_controller_;
};

#endif // HELLOAPPLICATION_H
