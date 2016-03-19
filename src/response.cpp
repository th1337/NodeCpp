#include "response.h"

using namespace std;
using namespace NodeCpp;

//Definition of status codes.
const int Response::HTTP_CONTINUE = 100;
const int Response::HTTP_SWITCHING_PROTOCOLS = 101;
const int Response::HTTP_PROCESSING = 102;
const int Response::HTTP_OK = 200;
const int Response::HTTP_CREATED = 201;
const int Response::HTTP_ACCEPTED = 202;
const int Response::HTTP_NON_AUTHORITATIVE_INFORMATION = 203;
const int Response::HTTP_NO_CONTENT = 204;
const int Response::HTTP_RESET_CONTENT = 205;
const int Response::HTTP_PARTIAL_CONTENT = 206;
const int Response::HTTP_MULTI_STATUS = 207;
const int Response::HTTP_ALREADY_REPORTED = 208;
const int Response::HTTP_IM_USED = 226;
const int Response::HTTP_MULTIPLE_CHOICES = 300;
const int Response::HTTP_MOVED_PERMANENTLY = 301;
const int Response::HTTP_FOUND = 302;
const int Response::HTTP_SEE_OTHER = 303;
const int Response::HTTP_NOT_MODIFIED = 304;
const int Response::HTTP_USE_PROXY = 305;
const int Response::HTTP_RESERVED = 306;
const int Response::HTTP_TEMPORARY_REDIRECT = 307;
const int Response::HTTP_PERMANENTLY_REDIRECT = 308;
const int Response::HTTP_BAD_REQUEST = 400;
const int Response::HTTP_UNAUTHORIZED = 401;
const int Response::HTTP_PAYMENT_REQUIRED = 402;
const int Response::HTTP_FORBIDDEN = 403;
const int Response::HTTP_NOT_FOUND = 404;
const int Response::HTTP_METHOD_NOT_ALLOWED = 405;
const int Response::HTTP_NOT_ACCEPTABLE = 406;
const int Response::HTTP_PROXY_AUTHENTICATION_REQUIRED = 407;
const int Response::HTTP_REQUEST_TIMEOUT = 408;
const int Response::HTTP_CONFLICT = 409;
const int Response::HTTP_GONE = 410;
const int Response::HTTP_LENGTH_REQUIRED = 411;
const int Response::HTTP_PRECONDITION_FAILED = 412;
const int Response::HTTP_REQUEST_ENTITY_TOO_LARGE = 413;
const int Response::HTTP_REQUEST_URI_TOO_LONG = 414;
const int Response::HTTP_UNSUPPORTED_MEDIA_TYPE = 415;
const int Response::HTTP_REQUESTED_RANGE_NOT_SATISFIABLE = 416;
const int Response::HTTP_EXPECTATION_FAILED = 417;
const int Response::HTTP_I_AM_A_TEAPOT = 418;
const int Response::HTTP_UNPROCESSABLE_ENTITY = 422;
const int Response::HTTP_LOCKED = 423;
const int Response::HTTP_FAILED_DEPENDENCY = 424;
const int Response::HTTP_RESERVED_FOR_WEBDAV_ADVANCED_COLLECTIONS_EXPIRED_PROPOSAL = 425;
const int Response::HTTP_UPGRADE_REQUIRED = 426;
const int Response::HTTP_PRECONDITION_REQUIRED = 428;
const int Response::HTTP_TOO_MANY_REQUESTS = 429;
const int Response::HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE = 431;
const int Response::HTTP_UNAVAILABLE_FOR_LEGAL_REASONS = 451;
const int Response::HTTP_INTERNAL_SERVER_ERROR = 500;
const int Response::HTTP_NOT_IMPLEMENTED = 501;
const int Response::HTTP_BAD_GATEWAY = 502;
const int Response::HTTP_SERVICE_UNAVAILABLE = 503;
const int Response::HTTP_GATEWAY_TIMEOUT = 504;
const int Response::HTTP_VERSION_NOT_SUPPORTED = 505;
const int Response::HTTP_VARIANT_ALSO_NEGOTIATES_EXPERIMENTAL = 506;
const int Response::HTTP_INSUFFICIENT_STORAGE = 507;
const int Response::HTTP_LOOP_DETECTED = 508;
const int Response::HTTP_NOT_EXTENDED = 510;
const int Response::HTTP_NETWORK_AUTHENTICATION_REQUIRED = 511;

//Definition of status texts.
const map<int, string> Response::HTTP_STATUS_TEXTS = {
    {100, "Continue"},
    {101, "Switching Protocols"},
    {102, "Processing"},
    {200, "OK"},
    {201, "Created"},
    {202, "Accepted"},
    {203, "Non-Authoritative Information"},
    {204, "No Content"},
    {205, "Reset Content"},
    {206, "Partial Content"},
    {207, "Multi-Status"},
    {208, "Already Reported"},
    {226, "IM Used"},
    {300, "Multiple Choices"},
    {301, "Moved Permanently"},
    {302, "Found"},
    {303, "See Other"},
    {304, "Not Modified"},
    {305, "Use Proxy"},
    {307, "Temporary Redirect"},
    {308, "Permanent Redirect"},
    {400, "Bad Request"},
    {401, "Unauthorized"},
    {402, "Payment Required"},
    {403, "Forbidden"},
    {404, "Not Found"},
    {405, "Method Not Allowed"},
    {406, "Not Acceptable"},
    {407, "Proxy Authentication Required"},
    {408, "Request Timeout"},
    {409, "Conflict"},
    {410, "Gone"},
    {411, "Length Required"},
    {412, "Precondition Failed"},
    {413, "Payload Too Large"},
    {414, "URI Too Long"},
    {415, "Unsupported Media Type"},
    {416, "Range Not Satisfiable"},
    {417, "Expectation Failed"},
    {418, "I'm a teapot"},
    {422, "Unprocessable Entity"},
    {423, "Locked"},
    {424, "Failed Dependency"},
    {425, "Reserved for WebDAV advanced collections expired proposal"},
    {426, "Upgrade Required"},
    {428, "Precondition Required"},
    {429, "Too Many Requests"},
    {431, "Request Header Fields Too Large"},
    {451, "Unavailable For Legal Reasons"},
    {500, "Internal Server Error"},
    {501, "Not Implemented"},
    {502, "Bad Gateway"},
    {503, "Service Unavailable"},
    {504, "Gateway Timeout"},
    {505, "HTTP Version Not Supported"},
    {507, "Insufficient Storage"},
    {508, "Loop Detected"},
    {510, "Not Extended"},
    {511, "Network Authentication Required"}
};

Response::Response() : status_code_(200), status_text_("OK"), headers_(), content_("")
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
        map<int, string>::const_iterator itCode = HTTP_STATUS_TEXTS.find(status_code);
        if (itCode != HTTP_STATUS_TEXTS.end()) {
            status_text_ = itCode->second;
        } else {
            status_text_ = "Unknown status code";
        }
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

void Response::Send(ostream& output_stream) const
{
    output_stream << "Status: " << status_code_ << " " << status_text_ << "\r\n";
    //Headers
    for (map<string, string>::const_iterator it_header = headers_.begin();it_header != headers_.end();++it_header)
    {
        output_stream << it_header->first << ": " << it_header->second << "\r\n";
    }
    output_stream <<  "\r\n";
    output_stream << content_;
}