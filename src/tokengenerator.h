#ifndef TOKENGENERATOR_H
#define TOKENGENERATOR_H

#include <string>
#include "user.h"

using namespace std;

namespace NodeCpp
{

class TokenGenerator
{
public:
    TokenGenerator(int seed);
    string GenerateToken(const User* user) const;

private:
    int seed_; //the seed of the generator
};

}

#endif // TOKENGENERATOR_H
