#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <map>
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
        typedef Response (Controller::*ControllerAction)(const Request&);

        Application();
        ~Application();
        void AddRoute(string url, ControllerAction funct, Controller* controller);
        void InitRoutes();
        void Init();
        void Run();

    private :
        void ProcessRequest();

        //Streambuf backups.
        streambuf * cin_streambuf_;
        streambuf * cout_streambuf_;
        streambuf * cerr_streambuf_;

        //radix tree
        RadixUrlTree url_tree_;
        vector<pair<ControllerAction,Controller*>> routes_;

        FCGX_Request fgci_request_;

        Controller hello_controller;



    };
}

#endif // APPLICATION_H
