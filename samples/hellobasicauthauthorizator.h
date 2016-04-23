#ifndef HELLOBASICAUTHAUTHORIZATOR_H
#define HELLOBASICAUTHAUTHORIZATOR_H


#include "authorizator.h"

using namespace NodeCpp;

class HelloBasicAuthAuthorizator : public Authorizator
{
public:
    HelloBasicAuthAuthorizator();
    virtual bool Accept(const Request& request) override;
};

#endif // HELLOBASICAUTHAUTHORIZATOR_H
