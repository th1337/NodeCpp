#include "nodeauthenticator.h"
#include "anonymoususer.h"

using namespace std;
using namespace NodeCpp;

const string NodeAuthenticator::LOGIN_PARAM = "login";
const string NodeAuthenticator::PASSWORD_PARAM = "password";
const string NodeAuthenticator::TOKEN_PARAM = "token";

NodeAuthenticator::NodeAuthenticator(TokenGenerator* generator) : tokenGenerator_(generator)
{

}

NodeAuthenticator::~NodeAuthenticator()
{

}

User* NodeAuthenticator::HandleUser(const Request &request) {
    string token = ReadToken(request);
    
    if(!token.empty()) {
        //There is a token in the request.
        User* user = AuthenticateToken(token);
        if (user != nullptr) {
            return user;
        }
    }
    //Return an anonymous User.
    return new AnonymousUser();
}

string NodeAuthenticator::ReadToken(const Request& request) {
    return request.GetQueryParameter(TOKEN_PARAM, "");
}

string NodeAuthenticator::LogIn(const string& login, const string& password) {
    string token("");
    User* user = AuthenticateUser(login, password);
    //If the user is not anonymous.
    if(user != nullptr && !user->IsAnonymous()) {
        token = tokenGenerator_->GenerateToken(user);
        StoreToken(token, user);
    }
    delete user;
    
    return token;
}

void NodeAuthenticator::LogOut(const string& token) {
    RemoveToken(token);
}