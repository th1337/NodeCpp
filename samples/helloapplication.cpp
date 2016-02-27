#include "helloapplication.h"

using namespace std;

HelloApplication::HelloApplication()
{

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

void HelloApplication::InitControllers()
{
    hello_controller.Init();
    sort_controller.Init();
}
