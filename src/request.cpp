#include <iostream>
#include <cstring>
#include <map>
#include "request.h"

using namespace std;
using namespace NodeCpp;

const unsigned long STDIN_MAX = 1000000;

/**
 * Note this is not thread safe due to the static allocation of the
 * content_buffer.
 */
string get_request_content(const FCGX_Request & request)
{
    char * content_length_str = FCGX_GetParam("CONTENT_LENGTH", request.envp);
    unsigned long content_length = STDIN_MAX;

    if (content_length_str) {
        content_length = strtol(content_length_str, &content_length_str, 10);
        if (*content_length_str) {
            cerr << "Can't Parse 'CONTENT_LENGTH='"
                 << FCGX_GetParam("CONTENT_LENGTH", request.envp)
                 << "'. Consuming stdin up to " << STDIN_MAX << endl;
        }

        if (content_length > STDIN_MAX) {
            content_length = STDIN_MAX;
        }
    } else {
        // Do not read from stdin if CONTENT_LENGTH is missing
        content_length = 0;
    }

    char * content_buffer = new char[content_length];
    cin.read(content_buffer, content_length);
    content_length = cin.gcount();

    // Chew up any remaining stdin - this shouldn't be necessary
    // but is because mod_fastcgi doesn't handle it correctly.

    // ignore() doesn't set the eof bit in some versions of glibc++
    // so use gcount() instead of eof()...
    do cin.ignore(1024); while (cin.gcount() == 1024);

    string content(content_buffer, content_length);
    delete [] content_buffer;
    return content;
}

void ExtractQueryParameters(string s, map<string,string> & parameters)
{
    std::string delimiter = "&";
    std::string equal = "=";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if(token.length()>0){ // we have a parameter assignement (x=y)

            int position_eq = token.find(equal);
            string var_name = token.substr(0, position_eq);
            string var_value = token.substr(position_eq+1, token.length());

            parameters[var_name] = var_value;
        }
        s.erase(0, pos + delimiter.length());
    }

    if(s.size()>0){
        int position_eq = s.find(equal);
        string var_name = s.substr(0, position_eq);
        string var_value = s.substr(position_eq+1, s.length());

        parameters[var_name] = var_value;
    }

}



Request::Request(const FCGX_Request& request)
{
    const char * uriR = FCGX_GetParam("REQUEST_URI", request.envp);
    const char * methodR = FCGX_GetParam("REQUEST_METHOD", request.envp);
    const char * remoteR = FCGX_GetParam("REMOTE_ADDR", request.envp);
    const char * remote_portR = FCGX_GetParam("REMOTE_PORT", request.envp);
    const char * server_portR = FCGX_GetParam("SERVER_PORT", request.envp);
    const char * query_string = FCGX_GetParam("QUERY_STRING", request.envp);
    const char * auth_typeR = FCGX_GetParam("AUTH_TYPE", request.envp);

    string query(query_string);

    ExtractQueryParameters(query, query_params);

    uri_.assign(uriR, strlen(uriR));
    method_.assign(methodR, strlen(methodR));
    remote_.assign(remoteR, strlen(remoteR));
    auth_type_.assign(auth_typeR, strlen(auth_typeR));
    remote_port_ = atoi(remote_portR);
    server_port_ = atoi(server_portR);

    content = get_request_content(request);
}

void Request::print_infos(ostream &stream) const
{
    stream << method << " " << remote << ":" << remote_port << " " << uri << ":" << server_port << " content : " << content << endl;
}

string Request::GetParameter(const string& name, const string& default_value) const
{
    map<string, string>::const_iterator it_param = params.find(name);

    if(it_param != params.end())
    {
        return it_param->second;
    }
    else
    {
        return default_value;
    }
    
}

string Request::GetQueryParameter(const string& parameter_name, const string& default_value) const
{
    map<string,string>::const_iterator it = query_params.find(parameter_name);

    if(it!=query_params.end()){
        return it->second;
    }
    else
    {
        return default_value;
    }

}











