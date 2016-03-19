#include "authenticator.h"

using namespace NodeCpp;
using namespace std;

Authenticator::Authenticator(TokenGenerator* generator):tokenGenerator(generator)
{

}

int Authenticator::Handle(Request &request){
    string token = request.GetQueryParameter(TOKEN, "");
    string login;
    string password;
    if(token.compare("")!=0){
        //there is a token
        return AuthenticateToken(token);

    }else if((login=request.GetQueryParameter(LOGIN, "")).compare("")!=0 && (password=request.GetQueryParameter(PASSWORD, "")).compare("")!=0){
        //we have to generate a token
        int id = AuthenticateUser(login, password);

        if(id>0){
             string token = GenerateToken(id);
             StoreToken(token, id);
        }

        return -1;
    }

    return -1;
}

