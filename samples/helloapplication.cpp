#include "helloapplication.h"

using namespace std;

HelloApplication::HelloApplication() : 
    token_generator_(42),
    authenticator_(&token_generator_),
    security_controller_(authenticator_)
{
    AddController(&hello_controller_);
    AddController(&sort_controller_);
    AddController(&basic_controller_);
}

HelloApplication::~HelloApplication()
{

}

void HelloApplication::InitRoutes()
{
   //Here, add the routes
   AddRoute("/", NODECPP_ACTION(HelloController::HtmlHelloWorld), &hello_controller_);
   AddRoute("/sort", NODECPP_ACTION(SortController::Sort), &sort_controller_);
   AddRoute("/security/login", NODECPP_ACTION(SecurityController::Login), &security_controller_, &authenticator_);
   AddRoute("/security/secret-code", NODECPP_ACTION(SecurityController::SecretAction), &security_controller_, &authenticator_, &authorizator_);
   AddRoute("/private", NODECPP_ACTION(HelloBasicAuthController::HtmlHelloWorldProtected), &basic_controller_, &basic_authenticator_);
   AddRoute("hello/{name}/world", NODECPP_ACTION(HelloController::HtmlHelloWorldNominative), &hello_controller_);
}

