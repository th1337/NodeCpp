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
        inline string GetUri(){return uri;}
        string GetParameter(string parameter_name) const;
        string GetQueryParameter(string parameter_name) const;
        inline void SetParameters(map<string, string> parameters){params = parameters;}
        void print_infos(ostream &stream);

    private :
        string method;
        string content;
        string uri;
        string remote;
        int server_port;
        int remote_port;
        map<string, string> params;
        map<string, string> query_params;
    };
}

#endif // REQUEST_H
