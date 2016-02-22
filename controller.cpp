#include "controller.h"
#include <sstream>

using namespace std;
using namespace NodeCpp;

Controller::Controller()
{

}

Controller::~Controller()
{
    
}

void Controller::Init()
{

}

void Controller::PreDispatch()
{

}

void Controller::PostDispatch()
{

}

Response Controller::HtmlHelloWorld(const Request& request)
{
    Response response;

    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>Hello, World!</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>Hello World !</h1>\n"
                    << "  </body>\n"
                    << "</html>\n";

    response.SetStatusCode(200, "OK");
    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}