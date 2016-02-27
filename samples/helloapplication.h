#ifndef HELLOAPPLICATION_H
#define HELLOAPPLICATION_H

#include "application.h"
#include "hellocontroller.h"
#include "sortcontroller.h"

using namespace NodeCpp;

class HelloApplication : public Application
{
public:
    HelloApplication();
    ~HelloApplication();

protected:
    void InitRoutes();
    void InitControllers();

private :
    HelloController hello_controller;
    SortController sort_controller;
};

#endif // HELLOAPPLICATION_H
