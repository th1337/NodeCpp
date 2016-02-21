#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iostream>
#include "fcgio.h"

using namespace std;

// Maximum bytes
const unsigned long STDIN_MAX = 1000000;

/**
 * Note this is not thread safe due to the static allocation of the
 * content_buffer.
 */
string get_request_content(const FCGX_Request & request) {
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



class NodeRequest{

public:
    NodeRequest(FCGX_Request & request){

        const char * uriR = FCGX_GetParam("REQUEST_URI", request.envp);
        const char * methodR = FCGX_GetParam("REQUEST_METHOD", request.envp);
        const char * remoteR = FCGX_GetParam("REMOTE_ADDR", request.envp);
        const char * remote_portR = FCGX_GetParam("REMOTE_PORT", request.envp);
        const char * server_portR = FCGX_GetParam("SERVER_PORT", request.envp);


        uri.assign(uriR, strlen(uriR));
        method.assign(methodR, strlen(methodR));
        remote.assign(remoteR, strlen(remoteR));
        remote_port = atoi(remote_portR);
        server_port = atoi(server_portR);

        content = get_request_content(request);

    }

    void print_infos(ostream & stream){

        stream<<method<<" "<<remote<<":"<<remote_port<<" "<<uri<<":"<<server_port<<" content : "<<content<<endl;



    }

private :
    string method;
    string content;
    string uri;
    string remote;
    int server_port;
    int remote_port;



};


int main(void) {
    // Backup the stdio streambufs
    streambuf * cin_streambuf  = cin.rdbuf();
    streambuf * cout_streambuf = cout.rdbuf();
    streambuf * cerr_streambuf = cerr.rdbuf();

    std::ofstream file_log("server.log");// to log
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

        /**printf(method);
        printf(" ");
        printf(from);
        printf(" url : ");
        printf(uri);
        printf("\n");*/

        NodeRequest curr_request(request);

        curr_request.print_infos(file_log);
        curr_request.print_infos(console_log);

        string content = get_request_content(request);

        if (content.length() == 0) {
            content = ", World!";
        }
        cerr<<"go for it"<<endl;
        cout << "Content-type: text/html\r\n"
             << "\r\n"
             << "<html>\n"
             << "  <head>\n"
             << "    <title>Hello, World!</title>\n"
             << "  </head>\n"
             << "  <body>\n"
             << "    <h1>Hello " << content << " from " << " !</h1>\n"
             << "  </body>\n"
             << "</html>\n";

        // Note: the fcgi_streambuf destructor will auto flush
    }

    // restore stdio streambufs
    cin.rdbuf(cin_streambuf);
    cout.rdbuf(cout_streambuf);
    cerr.rdbuf(cerr_streambuf);

    return 0;
}
