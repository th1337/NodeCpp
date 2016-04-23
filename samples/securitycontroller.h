#ifndef SECURITYCONTROLLER_H
#define SECURITYCONTROLLER_H

#include "controller.h"
#include "inmemoryauthenticator.h"

using namespace NodeCpp;

class SecurityController : public Controller
{
public:
    SecurityController(InMemoryAuthenticator& authenticator);
    ~SecurityController();
    void Init();
    void PreDispatch();
    void PostDispatch();
    
    /**
     * This action is used to log an user in the application.
     */
    Response LogIn(const Request& request);
    
    /**
     * This action is a secret action accessible only by authorized users.
     */
    Response SecretAction(const Request& request);

private:
    InMemoryAuthenticator& authenticator_;
};

#endif // SECURITYCONTROLLER_H
