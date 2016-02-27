#ifndef HELLOCONTROLLER_H
#define HELLOCONTROLLER_H

#include "controller.h"

using namespace NodeCpp;

class HelloController : public Controller
{
public:
    HelloController(){}
    ~HelloController();
    void Init();
    void PreDispatch();
    void PostDispatch();

    Response HtmlHelloWorld(const Request& request);
    Response HtmlHelloWorldNominative(const Request& request);
};

#endif // HELLOCONTROLLER_H
