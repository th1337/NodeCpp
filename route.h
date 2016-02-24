#ifndef ROUTE_H
#define ROUTE_H

#include "controller.h"

namespace NodeCpp
{
    class Route
    {
    public:
        Route(Controller* c, Controller::ControllerAction& a) : controller(c), action(a){}
        Controller* GetController() const {return controller;}
        Controller::ControllerAction GetControllerAction() const {return action;}
    private:
        Controller* controller;
        Controller::ControllerAction action;
    };
}
#endif // ROUTE_H
