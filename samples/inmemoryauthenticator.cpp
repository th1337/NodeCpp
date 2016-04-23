#include "inmemoryauthenticator.h"
#include "customuser.h"
#include <typeinfo>

InMemoryAuthenticator::InMemoryAuthenticator(TokenGenerator* generator) : NodeAuthenticator(generator)
{
    
}

InMemoryAuthenticator::~InMemoryAuthenticator()
{
    
}

User* InMemoryAuthenticator::AuthenticateToken(const string& token)
{    
    map<string, int>::const_iterator itToken(tokens_.find(token));
    if (itToken != tokens_.end())
    {
        int id = itToken->second;
        
        //According to the user id, create an User object.
        if (id == 1)
        {
            CustomUser* user = new CustomUser(1, "demo", "test");
            
            return user;
        }
    }
    
    return nullptr;
}
    
User* InMemoryAuthenticator::AuthenticateUser(const string& login, const string& password)
{
    if (login.compare("demo") == 0 and password.compare("test") == 0)
    {
        CustomUser* user = new CustomUser(1, "demo", "test");
        return user;
    }
    
    return nullptr;
}

void InMemoryAuthenticator::StoreToken(const string& token, const User* user)
{
    const CustomUser* customUser = dynamic_cast<const CustomUser*>(user);
    
    if (customUser != nullptr)
    {
        tokens_[token] = customUser->GetId();
    }
}

void InMemoryAuthenticator::RemoveToken(const string& token)
{
    tokens_.erase(token);
}