#ifndef TODOAPPLICATION_H
#define TODOAPPLICATION_H

#include "application.h"
#include "todocontroller.h"
#include "todofirewall.h"

using namespace NodeCpp;

class TodoApplication : public Application
{
public:
    TodoApplication();
    ~TodoApplication();

protected:
    void InitRoutes();

private :
    TodoFirewall todoFirewall_;
    TodoController todoController_;

};

#endif // TODOAPPLICATION_H
