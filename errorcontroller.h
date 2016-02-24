#ifndef ERRORCONTROLLER_H
#define ERRORCONTROLLER_H

#include "controller.h"


namespace NodeCpp
{
    class ErrorController : public Controller
    {
    public:
        ErrorController();
        ~ErrorController();
        void Init();
        void PreDispatch();
        void PostDispatch();

        Response Error404(const Request& request);



    };
}

#endif // ERRORCONTROLLER_H