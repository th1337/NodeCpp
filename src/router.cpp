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

        return route;

    }

    return Route(error_controller_, static_cast<Controller::ControllerAction>(&ErrorController::Error404));

}


void Router::AddRoute(string url, Controller::ControllerAction controller_action, Controller* controller)
{
    //insertion of the route in the tree
    int code = routes_.size();

    url_tree_.Insert(url, code);
    routes_.push_back(Route(controller, controller_action));

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
