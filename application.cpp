#include "application.h"
#include "request.h"
#include "response.h"
#include "radixurltree.h"
#include <sstream>

using namespace std;
using namespace NodeCpp;

Application::Application() : cin_streambuf_(nullptr), cout_streambuf_(nullptr), cerr_streambuf_(nullptr), console(cout.rdbuf())
{

}

Application::~Application()
{
    // Restore stdio streambufs
    cin.rdbuf(cin_streambuf_);
    cout.rdbuf(cout_streambuf_);
    cerr.rdbuf(cerr_streambuf_);
}

void Application::AddRoute(string url, ControllerAction funct, Controller* controller)
{
    //insertion of the route in the tree
    int code = routes_.size();
    url_tree_.Insert(url, code);
    routes_.push_back(make_pair(funct, controller));
}


void Application::InitRoutes()
{
   //Here add the routes
   AddRoute("/", &Controller::HtmlHelloWorld, &hello_controller);
   AddRoute("hello/{name}/world", &Controller::HtmlHelloWorldNominative, &hello_controller);


}

void Application::Init()
{
    // Backup the stdio streambufs
    cin_streambuf_  = cin.rdbuf();
    cout_streambuf_ = cout.rdbuf();
    cerr_streambuf_ = cerr.rdbuf();

    //Controllers init
    hello_controller.Init();

    InitRoutes();

    //FastCGI init.
    FCGX_Init();
    FCGX_InitRequest(&fgci_request_, 0, 0);



}

void Application::Run()
{
    while (FCGX_Accept_r(&fgci_request_) == 0)
    {
        fcgi_streambuf cin_fcgi_streambuf(fgci_request_.in);
        fcgi_streambuf cout_fcgi_streambuf(fgci_request_.out);
        fcgi_streambuf cerr_fcgi_streambuf(fgci_request_.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        ProcessRequest();

        // Note: the fcgi_streambuf destructor will auto flush
    }
}


void Application::ProcessRequest()
{

    Request request(fgci_request_);
    Response response;

    string url = request.GetUri();

    RadixUrlTree::RadixAnalyse analyse = url_tree_.FindUrl(url);

    if(analyse.found_){

        pair<ControllerAction, Controller*> route = routes_[analyse.code_];

        Controller* controller(route.second);

        ControllerAction action = route.first;

        request.SetParameters(analyse.args_);

        controller->PreDispatch();
        response = (controller->*action)(request);
        controller->PostDispatch();

        response.Send(cout);

    }



}

