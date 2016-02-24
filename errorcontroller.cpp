#include "errorcontroller.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace NodeCpp;

ErrorController::~ErrorController()
{

}

void ErrorController::Init()
{

}

void ErrorController::PreDispatch()
{

}

void ErrorController::PostDispatch()
{

}

Response ErrorController::Error404(const Request& request)
{
    Response response;

    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>Not Found</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>404 - Not Found</h1>\n"
                    << "  </body>\n"
                    << "</html>\n";

    response.SetStatusCode(404, "NOT_FOUND");
    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}


