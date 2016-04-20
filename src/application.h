#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <map>
#include <vector>
#include <ostream>
#include "controller.h"
#include "errorcontroller.h"
#include "fcgio.h"
#include "response.h"
#include "request.h"
#include "radixurltree.h"
#include "router.h"
#include "firewall.h"
#include "authorizator.h"

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
        void AddRoute(string url, Controller::ControllerAction controller_action, Controller* controller, Authenticator* authenticator = nullptr, Authorizator* authorizator = nullptr, Firewall* firewall = nullptr);
        void AddController(Controller* controller);
        void SetErrorController(ErrorController& error_controller);
        virtual void InitRoutes() = 0;

        ostream console;

    private :
        void ProcessRequest();
        void InitControllers();

        //Streambuf backups.
        streambuf * cin_streambuf_;
        streambuf * cout_streambuf_;
        streambuf * cerr_streambuf_;

        //Error controller
        ErrorController error_controller_;

        vector<Controller*> controllers_;

        //Routes
        Router router_;

        FCGX_Request fgci_request_;
    };
}

#endif // APPLICATION_H
