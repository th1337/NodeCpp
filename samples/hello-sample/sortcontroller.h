#ifndef SORTCONTROLLER_H
#define SORTCONTROLLER_H

#include "controller.h"

using namespace NodeCpp;

class SortController : public Controller
{
public:
    SortController(){}
    ~SortController();
    void Init();
    void PreDispatch();
    void PostDispatch();

    Response Sort(const Request& request);
};

#endif // SORTCONTROLLER_H
