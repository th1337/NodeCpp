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
   AddRoute("/", NODECPP_ACTION(&HelloController::HtmlHelloWorld), &hello_controller);
   AddRoute("hello/{name}/world", NODECPP_ACTION(&HelloController::HtmlHelloWorldNominative), &hello_controller);
   AddRoute("/sort", NODECPP_ACTION(&SortController::Sort), &sort_controller);
}

void HelloApplication::InitControllers()
{
    hello_controller.Init();
    sort_controller.Init();
}
