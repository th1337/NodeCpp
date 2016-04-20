#include "tokengenerator.h"

using namespace NodeCpp;

TokenGenerator::TokenGenerator(int seed) : seed_(seed)
{

}


string TokenGenerator::GenerateToken(const User* user) const
{
    return "token";
}

