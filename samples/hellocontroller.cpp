#include "hellocontroller.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

HelloController::HelloController()
{

}

HelloController::~HelloController()
{

}

void HelloController::Init()
{

}

void HelloController::PreDispatch()
{

}

void HelloController::PostDispatch()
{

}

Response HelloController::HtmlHelloWorld(const Request& request)
{
    Response response;

    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title> Hello World</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>Hello World, welcome page</h1>\n";
                    request.PrintInfos(response_stream);

                    response_stream<< request.GetHeader("Ze", "toto")<<" and "<<request.GetHeader("AUTH", "titi")<<"  </body>\n"
                    << "</html>\n";


    if(request.GetHeader("Authorization","null").compare("null") !=0){
          response.SetStatusCode(200, "OK");

    }else{
          response.SetStatusCode(401, "OK");
          response.SetHeader("WWW-Authenticate", "Basic realm=\"WallyWorld\"");
    }

    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}

Response HelloController::HtmlHelloWorldNominative(const Request& request)
{
    Response response;

    string name = request.GetParameter("name", "unknown");

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
