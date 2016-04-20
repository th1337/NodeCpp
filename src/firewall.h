#ifndef FIREWALL_H
#define FIREWALL_H

#include "request.h"
using namespace std;

namespace NodeCpp 
{
    class Firewall
    {
    public:
        Firewall() {}
        virtual bool Accept(const Request& request) = 0;
    };
}

#endif // FIREWALL_H
