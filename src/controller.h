#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <functional>
#include "request.h"
#include "response.h"

using namespace std;

#define NODECPP_ACTION(controller_action) static_cast<Controller::ControllerAction>(&controller_action)

namespace NodeCpp 
{
    class Controller
    {
    public:

        typedef Response(Controller::* ControllerAction)(const Request&);

        Controller(){}
        virtual ~Controller();
        virtual void Init() = 0;
        virtual void PreDispatch() = 0;
        virtual void PostDispatch() = 0;
        virtual Response Error401(const Request& request);
        virtual Response Error403(const Request& request);
        virtual Response Error404(const Request& request);

    private:

    };
}

#endif // CONTROLLER_H
