#include "route.h"

using namespace NodeCpp;

Route::Route(Controller* controller, Controller::ControllerAction action, Firewall* firewall) : controller_(controller), action_(action), firewall_(firewall)
{

}