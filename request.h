#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include "fcgio.h"

using namespace std;

namespace NodeCpp 
{
	class Request
	{
	public:
	    Request(FCGX_Request &request);
	    void print_infos(ostream &stream);

	private :
	    string method;
	    string content;
	    string uri;
	    string remote;
	    int server_port;
	    int remote_port;
	};
}

#endif // REQUEST_H