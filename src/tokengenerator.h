#ifndef TOKENGENERATOR_H
#define TOKENGENERATOR_H

#include <string>

using namespace std;

namespace NodeCpp
{

class TokenGenerator
{
public:
    TokenGenerator(int seed);
    string GenerateToken(int id) const;

private:
    int seed_; //the seed of the generator
};

}

#endif // TOKENGENERATOR_H
