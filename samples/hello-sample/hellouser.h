#ifndef HELLOUSER_H
#define HELLOUSER_H

#include <string>
#include "user.h"

using namespace std;
using namespace NodeCpp;

class HelloUser : public User
{
public:

    HelloUser(string username, string password): User(), username(username), password(password){ this->NoMoreAnonymous(); }

    string GetUsername() const {return username;}
    /**
     * Test whether two users are the same.
     */
    virtual bool Equals(const User& otherUser) const {return false;}


protected:

private:
    string username;
    string password;
};




#endif // HELLOUSER_H
