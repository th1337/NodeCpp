#include "todofirewall.h"

TodoFirewall::TodoFirewall()
{

}


bool TodoFirewall::Accept(const Request& request)
{
    //We check the method of the request.
    return request.GetMethod().compare("GET") == 0 || request.GetMethod().compare("PUT") == 0;
}
