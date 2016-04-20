#include "authenticator.h"

using namespace NodeCpp;

Authenticator::Authenticator()
{

}

void Authenticator::Handle(Request& request)
{
    request.SetUser(AuthenticateUser(request));
}