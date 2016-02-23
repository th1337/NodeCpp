#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <map>
#include "fcgio.h"

using namespace std;

namespace NodeCpp 
{
    class Request
    {
    public:
        Request(FCGX_Request &request);
        string GetUri() const { return uri; }
        string GetMethod() const { return method; }
        string GetContent() const { return content; }
        string GetParameter(const string& name, const string& default_value) const;
        void SetParameters(const map<string, string>& parameters) { params = parameters; }
        void print_infos(ostream& stream) const;

    private :
        string method;
        string content;
        string uri;
        string remote;
        int server_port;
        int remote_port;
        map<string, string> params;
    };
}

#endif // REQUEST_H
