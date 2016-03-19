#ifndef TOKENGENERATOR_H
#define TOKENGENERATOR_H

#include <string>

using namespace std;

class TokenGenerator
{
public:
    TokenGenerator(int seed);
    string GenerateToken(int id);

private:
    int seed; //the seed of the generator
};

#endif // TOKENGENERATOR_H
