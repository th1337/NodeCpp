#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H


class Authenticator
{
public:
    Authenticator();
    virtual int Handle(Request& request) = 0 ;
};

#endif // AUTHENTICATOR_H
