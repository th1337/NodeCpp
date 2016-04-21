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


        string GetUri() const { return uri_; }
        string GetMethod() const { return method_; }
        string GetContent() const { return content_; }
        string GetAuthType() const { return auth_type_; }
        User* GetUser() const { return user_; };
        string GetParameter(const string& name, const string& default_value) const;
        string GetQueryParameter(const string& parameter_name, const string& default_value) const;
        string GetHeader(const string& name, const string& default_value) const;
        void SetParameters(const map<string, string>& parameters) { params_ = parameters; }
        void PrintInfos(ostream& stream) const;
        void SetUser(User* user);
        
        static void ExtractQueryParameters(string s, map<string,string> & parameters);

    private :
        string method_;
        string content_;
        string uri_;
        string remote_;
        string auth_type_;
        int server_port_;
        int remote_port_;
        map<string, string> params_;
        map<string, string> query_params_;
        map<string, string> headers_;
        User* user_;
    };
}

#endif // REQUEST_H
