#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <map>

using namespace std;

namespace NodeCpp 
{
    class Response
    {
    public:
        Response(ostream &output_stream);
        void SetStatusCode(int status_code, const string& status_text = "");
        void SetHeader(const string& name, const string& value);
        void SetContent(const string& content);
        void Send();

    private :
        ostream& output_stream_;

        int status_code_;
        string status_text_;
        map<string, string> headers_;
        string content_;
    };
}

#endif // RESPONSE_H