#ifndef ANONYMOUSUSER_H
#define ANONYMOUSUSER_H

#include "user.h"

namespace NodeCpp
{

class AnonymousUser : public User
{
public:
    AnonymousUser() : User() {};
    
    /**
     * Test whether two users are the same.
     * An anonymous user is different from any user.
     */
    virtual bool Equals(const User& otherUser) const override final {
        return otherUser.IsAnonymous();
    }
};

}

#endif // ANONYMOUSUSER_H
