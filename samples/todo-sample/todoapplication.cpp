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
    AddRoute("/api/todos", NODECPP_ACTION(TodoController::Action), &todoController_, nullptr, nullptr, &todoFirewall_);
    AddRoute("/api/todos", NODECPP_ACTION(TodoController::Action), &todoController_, nullptr, nullptr, &todoFirewall_);
}

