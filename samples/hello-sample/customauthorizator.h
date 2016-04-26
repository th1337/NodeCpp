#ifndef CUSTOMAUTHORIZATOR_H
#define CUSTOMAUTHORIZATOR_H

#include "authorizator.h"

using namespace NodeCpp;

class CustomAuthorizator : public Authorizator
{
public:
    CustomAuthorizator();
    virtual bool Accept(const Request& request) override;
};

#endif // CUSTOMAUTHORIZATOR_H
