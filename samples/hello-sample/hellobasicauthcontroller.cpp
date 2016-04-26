#include "sstream"
#include "hellobasicauthcontroller.h"
#include "hellouser.h"


using namespace NodeCpp;

HelloBasicAuthController::HelloBasicAuthController()
{

}

HelloBasicAuthController::~HelloBasicAuthController()
{

}

void HelloBasicAuthController::Init()
{

}

void HelloBasicAuthController::PreDispatch()
{

}

void HelloBasicAuthController::PostDispatch()
{

}



Response HelloBasicAuthController::HtmlHelloWorldProtected(const Request& request)
{
    Response response;

    HelloUser* helloUser = (HelloUser*) request.GetUser();
    string name = helloUser->GetUsername();

    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>Hello, World!</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>Hello World  by "<< name <<" !</h1>\n"
                    << "  </body>\n"
                    << "</html>\n";

    response.SetStatusCode(200, "OK");
    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}
