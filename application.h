#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <map>
#include "fcgio.h"
#include "response.h"
#include "request.h"
#include "radixurltree.h"
using namespace std;



namespace NodeCpp 
{

    typedef Response (*route_function)(Request);

    class Application
    {
    public:
        Application();
        ~Application();
        void AddRoute(string url, route_function funct);
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
        vector<route_function> routes;


        FCGX_Request request_;
    };
}

#endif // APPLICATION_H
