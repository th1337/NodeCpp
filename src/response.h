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
        Response();
        void SetStatusCode(int status_code, const string& status_text = "");
        void SetHeader(const string& name, const string& value);
        void SetContent(const string& content);
        void Send(ostream& output_stream) const;

        //Status Code       
        static const int HTTP_CONTINUE;
        static const int HTTP_SWITCHING_PROTOCOLS;
        static const int HTTP_PROCESSING;
        static const int HTTP_OK;
        static const int HTTP_CREATED;
        static const int HTTP_ACCEPTED;
        static const int HTTP_NON_AUTHORITATIVE_INFORMATION;
        static const int HTTP_NO_CONTENT;
        static const int HTTP_RESET_CONTENT;
        static const int HTTP_PARTIAL_CONTENT;
        static const int HTTP_MULTI_STATUS;
        static const int HTTP_ALREADY_REPORTED;
        static const int HTTP_IM_USED;
        static const int HTTP_MULTIPLE_CHOICES;
        static const int HTTP_MOVED_PERMANENTLY;
        static const int HTTP_FOUND;
        static const int HTTP_SEE_OTHER;
        static const int HTTP_NOT_MODIFIED;
        static const int HTTP_USE_PROXY;
        static const int HTTP_RESERVED;
        static const int HTTP_TEMPORARY_REDIRECT;
        static const int HTTP_PERMANENTLY_REDIRECT;
        static const int HTTP_BAD_REQUEST;
        static const int HTTP_UNAUTHORIZED;
        static const int HTTP_PAYMENT_REQUIRED;
        static const int HTTP_FORBIDDEN;
        static const int HTTP_NOT_FOUND;
        static const int HTTP_METHOD_NOT_ALLOWED;
        static const int HTTP_NOT_ACCEPTABLE;
        static const int HTTP_PROXY_AUTHENTICATION_REQUIRED;
        static const int HTTP_REQUEST_TIMEOUT;
        static const int HTTP_CONFLICT;
        static const int HTTP_GONE;
        static const int HTTP_LENGTH_REQUIRED;
        static const int HTTP_PRECONDITION_FAILED;
        static const int HTTP_REQUEST_ENTITY_TOO_LARGE;
        static const int HTTP_REQUEST_URI_TOO_LONG;
        static const int HTTP_UNSUPPORTED_MEDIA_TYPE;
        static const int HTTP_REQUESTED_RANGE_NOT_SATISFIABLE;
        static const int HTTP_EXPECTATION_FAILED;
        static const int HTTP_I_AM_A_TEAPOT;
        static const int HTTP_UNPROCESSABLE_ENTITY;
        static const int HTTP_LOCKED;
        static const int HTTP_FAILED_DEPENDENCY;
        static const int HTTP_RESERVED_FOR_WEBDAV_ADVANCED_COLLECTIONS_EXPIRED_PROPOSAL;
        static const int HTTP_UPGRADE_REQUIRED;
        static const int HTTP_PRECONDITION_REQUIRED;
        static const int HTTP_TOO_MANY_REQUESTS;
        static const int HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE;
        static const int HTTP_UNAVAILABLE_FOR_LEGAL_REASONS;
        static const int HTTP_INTERNAL_SERVER_ERROR;
        static const int HTTP_NOT_IMPLEMENTED;
        static const int HTTP_BAD_GATEWAY;
        static const int HTTP_SERVICE_UNAVAILABLE;
        static const int HTTP_GATEWAY_TIMEOUT;
        static const int HTTP_VERSION_NOT_SUPPORTED;
        static const int HTTP_VARIANT_ALSO_NEGOTIATES_EXPERIMENTAL;
        static const int HTTP_INSUFFICIENT_STORAGE;
        static const int HTTP_LOOP_DETECTED;
        static const int HTTP_NOT_EXTENDED;
        static const int HTTP_NETWORK_AUTHENTICATION_REQUIRED;

        static const map<int, string> HTTP_STATUS_TEXTS;

    private :
        int status_code_;
        string status_text_;
        map<string, string> headers_;
        string content_;
    };
}

#endif // RESPONSE_H