#ifndef BASICAUTHCONTROLLER_H
#define BASICAUTHCONTROLLER_H

#include "controller.h"


namespace NodeCpp
{
    class BasicAuthController : public Controller
    {
    public:
        BasicAuthController(){}
        ~BasicAuthController();
        void Init();
        void PreDispatch();
        void PostDispatch();

        virtual Response Error401(const Request& request);
        virtual Response Error403(const Request& request);
        virtual Response Error404(const Request& request);
    };
}

#endif // BASICAUTHCONTROLLER_H
