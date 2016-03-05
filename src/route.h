#ifndef ROUTE_H
#define ROUTE_H

#include "controller.h"
#include "firewall.h"

namespace NodeCpp
{
    class Route
    {
    public:
        Route(Controller* controller, Controller::ControllerAction action, Firewall* firewall = nullptr);
        Controller* GetController() const {return controller_;}
        Controller::ControllerAction GetControllerAction() const {return action_;}
        Firewall* GetFirewall() const {return firewall_;}
    private:
        Controller* controller_;
        Controller::ControllerAction action_;
        Firewall* firewall_;
    };
}
#endif // ROUTE_H
