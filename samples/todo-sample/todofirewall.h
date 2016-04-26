#ifndef TODOFIREWALL_H
#define TODOFIREWALL_H

#include "firewall.h"

using namespace NodeCpp;

class TodoFirewall : public Firewall
{
public:
    TodoFirewall();
    virtual bool Accept(const Request& request);
};

#endif // TODOFIREWALL_H
