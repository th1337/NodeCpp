#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
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

        FCGX_Request request_;
    };
}

#endif // APPLICATION_H