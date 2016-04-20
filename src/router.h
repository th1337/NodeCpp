#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
#include "route.h"
#include "request.h"
#include "controller.h"
#include "radixurltree.h"
#include "errorcontroller.h"

using namespace std;

namespace NodeCpp
{
    class Router
    {
    public:
        Router(ErrorController* error_controller):error_controller_(error_controller){}
        Route Match(Request& request);
        void AddRoute(string url, Controller::ControllerAction controller_action, Controller* controller, Authenticator* authenticator = nullptr, Firewall* firewall = nullptr);
        void SetErrorController(ErrorController* error_controller) {error_controller_ = error_controller;}
        void ExecuteRoute(const Route& route, const Request& request);

    private:

        //ErrorController
        ErrorController* error_controller_;

        //radix tree
        RadixUrlTree url_tree_;

        vector<Route> routes_;
    };
}
#endif // ROUTER_H
