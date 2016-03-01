#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <map>
#include <ostream>
#include "controller.h"
#include "errorcontroller.h"
#include "fcgio.h"
#include "response.h"
#include "request.h"
#include "radixurltree.h"
#include "router.h"

#define NODECPP_ACTION(controller_action) static_cast<Controller::ControllerAction>(controller_action)

using namespace std;

namespace NodeCpp 
{
    class Application
    {
    public:
        Application();
        ~Application();
        void Init();
        void Run();

    protected:

        void AddRoute(string url, Controller::ControllerAction controller_action, Controller* controller);
        void SetErrorController(ErrorController& error_controller);
        virtual void InitRoutes() = 0;
        virtual void InitControllers() = 0;

        ostream console;

    private :
        void ProcessRequest();

        //Streambuf backups.
        streambuf * cin_streambuf_;
        streambuf * cout_streambuf_;
        streambuf * cerr_streambuf_;

        //Error controller
        ErrorController error_controller_;

        //Routes
        Router router_;

        FCGX_Request fgci_request_;
    };
}

#endif // APPLICATION_H
