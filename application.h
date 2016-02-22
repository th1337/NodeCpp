#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "controller.h"
#include "fcgio.h"

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

    private :
        void ProcessRequest();

        //Streambuf backups.
        streambuf * cin_streambuf_;
        streambuf * cout_streambuf_;
        streambuf * cerr_streambuf_;

        FCGX_Request fgci_request_;

        Controller hello_controller;

        typedef Response (Controller::*ControllerAction)(const Request&);
    };
}

#endif // APPLICATION_H