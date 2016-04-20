#ifndef HELLOAPPLICATION_H
#define HELLOAPPLICATION_H

#include "application.h"
#include "hellocontroller.h"
#include "sortcontroller.h"
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
    HelloController hello_controller;
    SortController sort_controller;
    HelloBasicAuthController basic_controller;
    HelloBasicAuthAuthenticator basic_authenticator;
};

#endif // HELLOAPPLICATION_H
