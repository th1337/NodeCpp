#include "response.h"

using namespace std;
using namespace NodeCpp;

Response::Response(ostream& output_stream) : output_stream_(output_stream), status_code_(200), status_text_("OK")
{

}

void Response::SetStatusCode(int status_code, const string& status_text)
{
	status_code_ = status_code;

	if (!status_text.empty())
	{
		status_text_ = status_text;
	}
	else
	{
		//If the status_text is empty, it will be automatically populated for the known status code.
		status_text_ = "Default status text";
	}
}

void Response::SetContent(const string& content)
{
	content_ = content;
}

void Response::Send()
{
	output_stream_ << "Status: " << status_code_ << " " << status_text_ << "\r\n";
	output_stream_ << "Content-type: text/html" << "\r\n";
	output_stream_ <<  "\r\n";
	output_stream_ << content_;
}