#ifndef HELLOBASICAUTHCONTROLLER_H
#define HELLOBASICAUTHCONTROLLER_H

#include "basicauthcontroller.h"

using namespace NodeCpp;

class HelloBasicAuthController : public BasicAuthController
{
public:
    HelloBasicAuthController();
    ~HelloBasicAuthController();

    Response HtmlHelloWorldProtected(const Request& request);

    void Init();
    void PreDispatch();
    void PostDispatch();
};

#endif // HELLOBASICAUTHCONTROLLER_H
