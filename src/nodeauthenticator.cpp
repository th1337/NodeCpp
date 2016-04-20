#include "nodeauthenticator.h"

using namespace std;
using namespace NodeCpp;

const string NodeAuthenticator::LOGIN_PARAM = "login";
const string NodeAuthenticator::PASSWORD_PARAM = "password";
const string NodeAuthenticator::TOKEN_PARAM = "token";

NodeAuthenticator::NodeAuthenticator(TokenGenerator* generator):tokenGenerator_(generator)
{

}

int NodeAuthenticator::Handle(const Request &request) {
    string token = request.GetQueryParameter(TOKEN_PARAM, "");
    
    if(!token.empty()) {
        //There is a token in the request.
        return AuthenticateToken(token);
    }
    return -1;
}

string NodeAuthenticator::LogIn(const string& login, const string& password) {
    int id = AuthenticateUser(login, password);
    //If the user is not anonymous.
    if(id > 0) {
        string token = tokenGenerator_->GenerateToken(id);
        StoreToken(token, id);
    }
}