#include "route.h"

using namespace NodeCpp;

Route::Route(Controller* controller, Controller::ControllerAction action) : controller_(controller), action_(action)
{

}