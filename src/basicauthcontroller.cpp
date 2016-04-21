#include "basicauthcontroller.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace NodeCpp;

BasicAuthController::~BasicAuthController()
{

}

void BasicAuthController::Init()
{

}

void BasicAuthController::PreDispatch()
{

}

void BasicAuthController::PostDispatch()
{

}

Response BasicAuthController::Error401(const Request& request)
{
    Response response;
    request.GetUri();
    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>401 - Unauthorized content for basic...</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>401 - Unauthorized</h1>\n"
                    << "  </body>\n"
                    << "</html>\n";

    response.SetStatusCode(401, "Unauthorized");
    response.SetHeader("WWW-Authenticate", "Basic realm=\"Basic auth required\"");
    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}

Response BasicAuthController::Error403(const Request& request)
{
    Response response;
    request.GetUri();
    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>403 - Forbidden</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>403 - Forbidden</h1>\n"
                    << "  </body>\n"
                    << "</html>\n";

    response.SetStatusCode(403);
    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}

Response BasicAuthController::Error404(const Request& request)
{
    Response response;
    request.GetUri();
    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>404 - Not Found</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>404 - Not Found</h1>\n"
                    << "  </body>\n"
                    << "</html>\n";

    response.SetStatusCode(404);
    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}


