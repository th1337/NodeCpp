#ifndef ROUTE_H
#define ROUTE_H

#include "controller.h"

namespace NodeCpp
{
    class Route
    {
    public:
        Route(Controller* controller, Controller::ControllerAction action);
        Controller* GetController() const {return controller_;}
        Controller::ControllerAction GetControllerAction() const {return action_;}
    private:
        Controller* controller_;
        Controller::ControllerAction action_;
    };
}
#endif // ROUTE_H
