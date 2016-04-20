#include "route.h"

using namespace NodeCpp;

Route::Route(Controller* controller, Controller::ControllerAction action, Authenticator* authenticator, Firewall* firewall) :
    controller_(controller),
    action_(action),
    authenticator_(authenticator),
    firewall_(firewall)
{

}