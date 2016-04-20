#include "nodeauthenticator.h"

using namespace std;
using namespace NodeCpp;

const string NodeAuthenticator::LOGIN_PARAM = "login";
const string NodeAuthenticator::PASSWORD_PARAM = "password";
const string NodeAuthenticator::TOKEN_PARAM = "token";

NodeAuthenticator::NodeAuthenticator(TokenGenerator* generator):tokenGenerator_(generator)
{

}

User* NodeAuthenticator::HandleUser(const Request &request){
    string token = request.GetQueryParameter(TOKEN_PARAM, "");
    
    if(!token.empty()) {
        //There is a token in the request.
        return AuthenticateToken(token);
    }
    ///TODO: Return an anonymous User.
    return nullptr;
}

string NodeAuthenticator::LogIn(const string& login, const string& password) {
    User* user = AuthenticateUser(login, password);
    //If the user is not anonymous.
    if(user != nullptr && !user->IsAnonymous()) {
        string token = tokenGenerator_->GenerateToken(user);
        StoreToken(token, user);
    }
    
    delete user;
}