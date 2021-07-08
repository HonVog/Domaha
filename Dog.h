#pragma once
#include "Pet.h"
class Dog :
    public Pet
{
public:
    Dog() : Pet("Buch", false) {}
    Dog(std::string name) : Pet(name, false) {}
};

