#ifndef TODOAPPLICATION_H
#define TODOAPPLICATION_H

#include "application.h"
#include "todocontroller.h"
#include "todofirewall.h"
#include "hellobasicauthauthenticator.h"
#include "hellobasicauthauthorizator.h"

using namespace NodeCpp;

class TodoApplication : public Application
{
public:
    TodoApplication();
    ~TodoApplication();

protected:
    void InitRoutes();

private :
    TodoFirewall todoFirewall_;
    TodoController todoController_;

    HelloBasicAuthAuthenticator authenticator_;
    HelloBasicAuthAuthorizator authorizator_;


};

#endif // TODOAPPLICATION_H
