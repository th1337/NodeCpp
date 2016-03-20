#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "request.h"

namespace NodeCpp
{

class Authenticator
{
public:
    Authenticator();
    virtual int Handle(const Request& request) = 0 ;
};

}

#endif // AUTHENTICATOR_H
