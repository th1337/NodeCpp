#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>

using namespace std;

namespace NodeCpp 
{
	class Response
	{
	public:
	    Response(ostream &output_stream);
	    void SetStatusCode(int status_code, const string& status_text = "");
	    void SetContent(const string& content);
	    void Send();

	private :
		ostream& output_stream_;

		int status_code_;
		string status_text_;
		string content_;
	};
}

#endif // RESPONSE_H