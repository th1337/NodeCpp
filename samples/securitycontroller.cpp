#include "securitycontroller.h"
#include "customuser.h"
#include <sstream>
#include <iostream>

SecurityController::SecurityController(InMemoryAuthenticator& authenticator) : 
    authenticator_(authenticator)
{
    
}

SecurityController::~SecurityController()
{

}

void SecurityController::Init()
{

}

void SecurityController::PreDispatch()
{

}

void SecurityController::PostDispatch()
{

}

Response SecurityController::LogIn(const Request& request)
{
    Response response;
    stringstream response_stream;

    response.SetStatusCode(200, "OK");

    if (request.GetMethod().compare("POST") == 0)
    {
        //The user is sending his credentials.
        map<string, string> parameters;
        Request::ExtractQueryParameters(request.GetContent(), parameters);
        
        //Check the parameters.
        map<string, string>::const_iterator itLogin(parameters.find("login"));
        map<string, string>::const_iterator itPassword(parameters.find("password"));
        if (itLogin != parameters.end() and itPassword != parameters.end())
        {   
            string token = authenticator_.LogIn(itLogin->second, itPassword->second);
            
            if (!token.empty())
            {
                response_stream << "Your token : " << token << "\n";
            }
            else
            {
                response_stream << "Bad credentials.\n";
            }
        }
        
        response.SetHeader("Content-Type", "text/html");
    }
    else
    {
        //Explain the user
        response_stream << "<html>\n"
                        << "  <head>\n"
                        << "    <title>Secret code</title>\n"
                        << "  </head>\n"
                        << "  <body>\n"
                        << "    <h1>Login</h1>\n"
                        << "    <form method=\"post\">\n"
                        << "      <p><input type=\"text\" name=\"login\" placeholder=\"Username\"></p>\n"
                        << "      <p><input type=\"password\" name=\"password\" placeholder=\"Password\"></p>\n"
                        << "      <p><input type=\"submit\" value=\"Login\"></p>\n"
                        << "    </form>\n"
                        << "  </body>\n"
                        << "</html>\n";

        response.SetHeader("Content-Type", "text/html");
    }    

    response.SetContent(response_stream.str());

    return response;
}

Response SecurityController::SecretAction(const Request& request)
{
    Response response;

    stringstream response_stream;
    response_stream << "<html>\n"
                    << "  <head>\n"
                    << "    <title>Secret code</title>\n"
                    << "  </head>\n"
                    << "  <body>\n"
                    << "    <h1>Secret code</h1>\n"
                    << "    <p>The secret code is 42.</p>\n"
                    << "  </body>\n"
                    << "</html>\n";

    response.SetStatusCode(200, "OK");
    response.SetHeader("Content-Type", "text/html");
    response.SetContent(response_stream.str());

    return response;
}
