#ifndef CUSTOMUSER_H
#define CUSTOMUSER_H

#include "user.h"
#include <string>

using namespace std;
using namespace NodeCpp;

class CustomUser : public User
{
public:
    CustomUser(int id, const string& username, const string& password);
    
    int GetId() const { return id_; }
    string GetUsername() const { return username_; }
    string GetPassword() const { return password_; }
    
    /**
     * Test whether two users are the same.
     */
    virtual bool Equals(const User& otherUser) const override;
    
private:
    int id_;
    string username_;
    string password_;
};

#endif // CUSTOMUSER_H
