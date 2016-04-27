#ifndef TODOCONTROLLER_H
#define TODOCONTROLLER_H

#include "basicauthcontroller.h"

using namespace NodeCpp;

class TodoController : public BasicAuthController
{
public:
    TodoController();
    ~TodoController();
    void Init();
    void PreDispatch();
    void PostDispatch();

    Response Action(const Request& request);

protected:
    Response List(const Request& request);
    Response Save(const Request& request);

private:
    string data_;
};

#endif // TODOCONTROLLER_H
