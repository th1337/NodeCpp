#ifndef AUTHORIZATOR_H
#define AUTHORIZATOR_H

#include "request.h"

namespace NodeCpp
{

class Authorizator
{
public:
    Authorizator() {}
    virtual bool Accept(const Request& request) = 0 ;
};

}

#endif // AUTHORIZATOR_H
