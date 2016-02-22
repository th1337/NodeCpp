#include "application.h"
#include "request.h"
#include "response.h"
#include "radixurltree.h"
#include <sstream>

using namespace std;
using namespace NodeCpp;

Application::Application() : cin_streambuf_(nullptr), cout_streambuf_(nullptr), cerr_streambuf_(nullptr), request_()
{

}

Application::~Application()
{
    // Restore stdio streambufs
    cin.rdbuf(cin_streambuf_);
    cout.rdbuf(cout_streambuf_);
    cerr.rdbuf(cerr_streambuf_);
}

void Application::Init()
{
    // Backup the stdio streambufs
    cin_streambuf_  = cin.rdbuf();
    cout_streambuf_ = cout.rdbuf();
    cerr_streambuf_ = cerr.rdbuf();

    //FastCGI init.
    FCGX_Init();
    FCGX_InitRequest(&request_, 0, 0);
}

void Application::AddRoute(string url, route_function funct)
{
    //insertion of the route in the tree
    int code = routes.size();
    url_tree_.Insert(url, code);
    routes.push_back(funct);
}


void Application::Run()
{
    while (FCGX_Accept_r(&request_) == 0)
    {
        fcgi_streambuf cin_fcgi_streambuf(request_.in);
        fcgi_streambuf cout_fcgi_streambuf(request_.out);
        fcgi_streambuf cerr_fcgi_streambuf(request_.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        ProcessRequest();

        // Note: the fcgi_streambuf destructor will auto flush
    }
}


void Application::ProcessRequest()
{

    NodeCpp::Request curr_request(request_);
    NodeCpp::Response curr_response(cout);

    stringstream response_stream;

    string url = curr_request.GetUri();

    RadixUrlTree::RadixAnalyse analyse = url_tree_.FindUrl(url);

    if(analyse.found_){


    }



    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>Hello, World!</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>Hello World !</h1>\n"
                    << "  </body>\n"
                    << "</html>\n";

    curr_response.SetStatusCode(200, "OK");
    curr_response.SetHeader("Content-Type", "text/html");
    curr_response.SetContent(response_stream.str());

    curr_response.Send();
}
