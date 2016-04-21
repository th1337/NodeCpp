#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <map>
#include "fcgio.h"
#include "user.h"

using namespace std;

namespace NodeCpp 
{
    class Request
    {
    public:
        Request();
        Request(const FCGX_Request& request);
        ~Request();

        string GetUri() const { return uri; }
        string GetMethod() const { return method; }
        string GetContent() const { return content; }
        User* GetUser() const { return user_; };
        string GetParameter(const string& name, const string& default_value) const;
        string GetQueryParameter(const string& parameter_name, const string& default_value) const;
        void SetParameters(const map<string, string>& parameters) { params = parameters; }
        void PrintInfos(ostream& stream) const;
        void SetUser(User* user);
        
        static void ExtractQueryParameters(string s, map<string,string> & parameters);

    private :
        string method;
        string content;
        string uri;
        string remote;
        int server_port;
        int remote_port;
        map<string, string> params;
        map<string, string> query_params;
        User* user_;
    };
}

#endif // REQUEST_H
