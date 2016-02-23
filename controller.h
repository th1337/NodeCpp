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
        virtual ~Controller();
        virtual void Init() = 0;
        virtual void PreDispatch() = 0;
        virtual void PostDispatch() = 0;
    };
}

#endif // CONTROLLER_H
