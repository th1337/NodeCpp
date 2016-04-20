#include "router.h"
#include "response.h"
#include <fstream>

using namespace std;
using namespace NodeCpp;


Route Router::Match(Request& request)
{
    string url = request.GetUri();

    size_t pos_params = url.find('?');

    pos_params = pos_params == string::npos ? url.length() : pos_params;

    string url_wquery(url.substr(0, pos_params));

    RadixUrlTree::RadixAnalyse analyse = url_tree_.FindUrl(url_wquery);

    if(analyse.found_)
    {
        Route& route = routes_[analyse.code_];
        request.SetParameters(analyse.args_);

        //Test whether the firewall accept the request.
        if (route.GetFirewall() != nullptr && !route.GetFirewall()->Accept(request))
        {
            return Route(route.GetController(), NODECPP_ACTION(&Controller::Error403));
        }
        
        //Authentication of the user.
        if (route.GetAuthenticator() != nullptr)
        {
            route.GetAuthenticator()->Handle(request);
        }


        
        //Authorize the user.
        if (route.GetAuthorizator() != nullptr && !route.GetAuthorizator()->Accept(request))
        {
            if (request.GetUser()->IsAnonymous())
            {
                //The User is not authenticated.
                return Route(route.GetController(), NODECPP_ACTION(&Controller::Error401));
            }
            else
            {
                //This route is forbidden for the User.
                return Route(route.GetController(), NODECPP_ACTION(&Controller::Error403));
            }
        }else if(route.GetAuthorizator() == nullptr && request.GetUser()->IsAnonymous()){
            //The User is not authenticated.
            return Route(route.GetController(), NODECPP_ACTION(&Controller::Error401));
        }
        
        //The Firewall accepts the request, or no firewall is defined for this route.
        return route;
    }
    
    return Route(error_controller_, NODECPP_ACTION(&Controller::Error404));
}


void Router::AddRoute(string url, Controller::ControllerAction controller_action, Controller* controller, Authenticator* authenticator, Authorizator* authorizator, Firewall* firewall)
{
    //Insertion of the route in the tree.
    int code = routes_.size();

    url_tree_.Insert(url, code);
    routes_.push_back(Route(controller, controller_action, authenticator, authorizator, firewall));
}



void Router::ExecuteRoute(const Route& route, const Request& request)
{
    Response response;

    Controller * controller = route.GetController();
    Controller::ControllerAction controller_action = route.GetControllerAction();

    controller->PreDispatch();
    response = (controller->*controller_action)(request);
    controller->PostDispatch();

    response.Send(cout);
}
