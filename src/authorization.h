#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

namespace NodeCpp
{

class Authorization
{
public:
    Authorization() {}
    virtual bool Accept(const Request& request) = 0 ;
};

}

#endif // AUTHORIZATION_H
