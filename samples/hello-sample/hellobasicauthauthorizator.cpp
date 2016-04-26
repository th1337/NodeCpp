#include "hellobasicauthauthorizator.h"

HelloBasicAuthAuthorizator::HelloBasicAuthAuthorizator()
{

}

bool HelloBasicAuthAuthorizator::Accept(const Request& request)
{
    if(request.GetUser()->IsAnonymous()) {
        return false;

    }

    return true;
}
