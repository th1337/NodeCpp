#include "todoapplication.h"

using namespace std;

TodoApplication::TodoApplication()
{
    AddController(&todoController_);
}

TodoApplication::~TodoApplication()
{

}

void TodoApplication::InitRoutes()
{
    AddRoute("/api/todos", NODECPP_ACTION(TodoController::Action), &todoController_, &authenticator_, &authorizator_, &todoFirewall_);

}

