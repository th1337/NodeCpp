#include "helloapplication.h"

using namespace std;

HelloApplication::HelloApplication()
{
    AddController(&hello_controller);
    AddController(&sort_controller);
}

HelloApplication::~HelloApplication()
{

}

void HelloApplication::InitRoutes()
{
   //Here, add the routes
   AddRoute("/", static_cast<Controller::ControllerAction>(&HelloController::HtmlHelloWorld), &hello_controller);
   AddRoute("hello/{name}/world", static_cast<Controller::ControllerAction>(&HelloController::HtmlHelloWorldNominative), &hello_controller);
   AddRoute("/sort", static_cast<Controller::ControllerAction>(&SortController::Sort), &sort_controller);
}

