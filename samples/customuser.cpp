#include "customuser.h"
#include <typeinfo>

using namespace std;

CustomUser::CustomUser(int id, const string& username, const string& password) :
    User(),
    id_(id),
    username_(username),
    password_(password)
{
    NoMoreAnonymous();
}

bool CustomUser::Equals(const User& otherUser) const
{
    //Both users are anonymous.
    if (IsAnonymous() and otherUser.IsAnonymous())
    {
        return true;
    }
    
    try
    {
        const CustomUser& otherCustomUser = dynamic_cast<const CustomUser&>(otherUser);
        //Compare the two custom users.
        return id_ == otherCustomUser.GetId();
    }
    catch (bad_cast& bc)
    {
        //The other user is not a custom user.
        return false;
    }
}