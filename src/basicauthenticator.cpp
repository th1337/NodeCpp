#include "basicauthenticator.h"
#include "anonymoususer.h"
#include "tools.h"

using namespace NodeCpp;

const string BasicAuthenticator::PREFIX = "Basic";
const string BasicAuthenticator::AUTHORIZATION = "Authorization";

BasicAuthenticator::BasicAuthenticator()
{

}

/**
 * Extracts basic auth credentials. If the credentials are not well-formed, the returned pair is empty.
 * @brief ExtractCredentials
 * @param b64_credentials
 * @return A pair <username, password> or an empty pair. 
 */
pair<string, string> ExtractCredentials(string b64_credentials) {

    string decoded(base64_decode(b64_credentials));

    int index_sep = decoded.find(':');

    if(index_sep != string::npos && index_sep != 0 && index_sep != decoded.length() - 1) {

        string username(decoded.substr(0, index_sep));
        string password(decoded.substr(index_sep + 1, decoded.length()));

        return make_pair(username, password);
    }

    return make_pair("", "");
}

User* BasicAuthenticator::HandleUser(const Request& request)
{
    const string DEFAULT_AUTH_VALUE("null");

    string auth(request.GetHeader(AUTHORIZATION, DEFAULT_AUTH_VALUE));

    if(auth.compare(DEFAULT_AUTH_VALUE) != 0){ //there is potentially an user

        if(auth.length() > PREFIX.length() + 2){ //there is a space between the prefix and the authent string

            if(auth.substr(0, PREFIX.length()).compare(PREFIX) == 0) //the request seems well formed
            {
                string b64_credentials(auth.substr(PREFIX.length()+1, auth.length()));

                pair<string, string> credentials(ExtractCredentials(b64_credentials));

                if(!credentials.first.empty() && !credentials.second.empty()){ //check if the token is well-formed

                    User* user = AcceptCredentials(credentials.first, credentials.second);

                    return user;
                }
            }
        }
    }

    return new AnonymousUser(); //protocol issue
}

