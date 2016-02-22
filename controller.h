#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "request.h"
#include "response.h"

using namespace std;

namespace NodeCpp 
{
    class Controller
    {
    public:
        Controller();
        ~Controller();
        void Init();
        void PreDispatch();
        void PostDispatch();

        Response HtmlHelloWorld(const Request& request);
    };
}

#endif // CONTROLLER_H