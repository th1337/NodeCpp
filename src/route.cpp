#include "route.h"

using namespace NodeCpp;

Route::Route(Controller* controller, Controller::ControllerAction action, Authenticator* authenticator, Authorizator* authorizator, Firewall* firewall) :
    controller_(controller),
    action_(action),
    authenticator_(authenticator),
    authorizator_(authorizator),
    firewall_(firewall)
{

}