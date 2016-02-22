#include "response.h"

using namespace std;
using namespace NodeCpp;

Response::Response(ostream& output_stream) : output_stream_(output_stream), status_code_(200), status_text_("OK"), headers_(), content_("")
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

void Response::SetHeader(const string& name, const string& value)
{
	map<string, string>::iterator iterator = headers_.find(name);
	//If the key already exists.
	if (iterator != headers_.end())
	{
		//Replace the value.
		iterator->second = value;
	}
	else
	{
		//Insert a new header.
		headers_.insert(make_pair(name, value));
	}
}

void Response::SetContent(const string& content)
{
	content_ = content;
}

void Response::Send()
{
	output_stream_ << "Status: " << status_code_ << " " << status_text_ << "\r\n";
	//Headers
	for (map<string, string>::const_iterator it_header = headers_.begin();it_header != headers_.end();++it_header)
	{
		output_stream_ << it_header->first << ": " << it_header->second << "\r\n";
	}
	output_stream_ <<  "\r\n";
	output_stream_ << content_;
}