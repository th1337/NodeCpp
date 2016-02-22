#include <iostream>
#include <fstream>
#include <sstream>
#include "fcgio.h"
#include "radixurltree.h"
#include "request.h"
#include "response.h"

using namespace std;

int main(void) {
    // Backup the stdio streambufs
    streambuf * cin_streambuf  = cin.rdbuf();
    streambuf * cout_streambuf = cout.rdbuf();
    streambuf * cerr_streambuf = cerr.rdbuf();

    ofstream file_log("server.log");// to log
    ostream console_log(cout_streambuf);

    file_log<<"Lancement du serveur"<<endl;
    console_log<<"Lancement du serveur"<<endl;

    FCGX_Request request;

    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) == 0) {

        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        NodeCpp::Request curr_request(request);
        NodeCpp::Response curr_response(cout);

        stringstream response_stream;
        response_stream << "<html>\n"
                        << "  <head>\n"
                        << "    <title>Hello, World!</title>\n"
                        << "  </head>\n"
                        << "  <body>\n"
                        << "    <h1>Hello World !</h1>\n"
                        << "  </body>\n"
                        << "</html>\n";

        curr_response.SetStatusCode(200, "OK");
        curr_response.SetHeader("Content-Type", "text/html");
        curr_response.SetContent(response_stream.str());

        curr_response.Send();

        curr_request.print_infos(file_log);
        curr_request.print_infos(console_log);

        // Note: the fcgi_streambuf destructor will auto flush
    }

    // restore stdio streambufs
    cin.rdbuf(cin_streambuf);
    cout.rdbuf(cout_streambuf);
    cerr.rdbuf(cerr_streambuf);

    return 0;
}
