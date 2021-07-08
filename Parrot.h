#pragma once
#include "Pet.h"
class Parrot :
    public Pet
{
public:
    Parrot() : Pet("Tviti", true ){}
    Parrot(std::string name) : Pet(name, true) {}
};

