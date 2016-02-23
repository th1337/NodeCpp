#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <map>
#include <ostream>
#include <functional>
#include "controller.h"
#include "fcgio.h"
#include "response.h"
#include "request.h"
#include "radixurltree.h"

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
        typedef function<Response(const Request&)> ControllerAction;

        struct Route
        {
            Controller* controller;
            ControllerAction action;

            Route(Controller*& c, ControllerAction& a) : controller(c), action(a)
            {

            }
        };

        void AddRoute(string url, ControllerAction controller_action, Controller* controller);
        virtual void InitRoutes() = 0;
        virtual void InitControllers() = 0;

        ostream console;

    private :
        void ProcessRequest();

        //Streambuf backups.
        streambuf * cin_streambuf_;
        streambuf * cout_streambuf_;
        streambuf * cerr_streambuf_;

        //radix tree
        RadixUrlTree url_tree_;
        vector<Route> routes_;

        FCGX_Request fgci_request_;
    };
}

#endif // APPLICATION_H
