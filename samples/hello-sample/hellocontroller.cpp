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

#include "anonymoususer.h"
#include "customuser.h"
#include <typeinfo>

void TestMethod(User& user, stringstream& response_stream)
{
    response_stream << "1.1\n";
    user = CustomUser(1, "demo", "password");
    response_stream << "1.2\n";
    try
    {
        CustomUser& customUser = dynamic_cast<CustomUser&>(user);
        response_stream << "1.3\n";
        customUser.GetId();
        response_stream << "1.4\n";
    }
    catch (bad_cast& bc)
    {
        response_stream << "Bad Cast dans TestMethod\n";
    }
}

Response HelloController::HtmlHelloWorld(const Request& request)
{
    Response response;

    stringstream response_stream;
    
    AnonymousUser an_user;
    User& user(an_user);
    response_stream << "1\n";
    TestMethod(user, response_stream);
    response_stream << "2\n";
    try
    {
        CustomUser& customUser = dynamic_cast<CustomUser&>(user);
        response_stream << "3\n";
        customUser.GetId();
        response_stream << "4\n";
    }
    catch (bad_cast& bc)
    {
        response_stream << "Bad Cast dans HtmlHelloWorld\n";
    }
    
    /*
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
    */

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
