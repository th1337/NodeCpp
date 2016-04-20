#ifndef USER_H
#define USER_H

namespace NodeCpp
{

class User
{
public:
    User() : anonymous_(true) {};
    
    /**
     * Test whether two users are the same.
     */
    virtual bool Equals(const User& otherUser) = 0;
    
    /**
     * Return true if the User is anonymous, false otherwise.
     * @return True if the User is anonymous, false otherwise.
     */
    bool IsAnonymous() { return anonymous_; };
    
protected:
    /**
     * Set the User as not anonymous.
     */
    void NoMoreAnonymous() { anonymous_ = false; };
    
private:
    bool anonymous_;
};

}

#endif // USER_H
