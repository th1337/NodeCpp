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
        Request(const FCGX_Request& request);
        Request(){}

        string GetUri() const { return uri_; }
        string GetMethod() const { return method_; }
        string GetContent() const { return content_; }
        string GetAuthType() const { return auth_type_; }
        string GetParameter(const string& name, const string& default_value) const;
        string GetQueryParameter(const string& parameter_name, const string& default_value) const;
        void SetParameters(const map<string, string>& parameters) { params = parameters; }
        void print_infos(ostream& stream) const;


    private :
        string method_;
        string content_;
        string uri_;
        string remote_;
        string auth_type_;
        int server_por_t;
        int remote_port_;
        map<string, string> params;
        map<string, string> query_params;
    };
}

#endif // REQUEST_H
