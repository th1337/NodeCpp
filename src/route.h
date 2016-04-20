#ifndef ROUTE_H
#define ROUTE_H

#include "controller.h"
#include "firewall.h"
#include "authenticator.h"
#include "authorizator.h"

namespace NodeCpp
{
    class Route
    {
    public:
        Route(Controller* controller, Controller::ControllerAction action, Authenticator* authenticator = nullptr, Authorizator* authorizator = nullptr, Firewall* firewall = nullptr);
        Controller* GetController() const {return controller_;}
        Controller::ControllerAction GetControllerAction() const {return action_;}
        Authenticator* GetAuthenticator() const {return authenticator_;}
        Authorizator* GetAuthorizator() const {return authorizator_;}
        Firewall* GetFirewall() const {return firewall_;}
    private:
        Controller* controller_;
        Controller::ControllerAction action_;
        Authenticator* authenticator_;
        Authorizator* authorizator_;
        Firewall* firewall_;
    };
}
#endif // ROUTE_H
