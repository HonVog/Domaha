#pragma once
#include "Pet.h"
class Cat :
    public Pet
{
public:
    Cat() : Pet("Pusi", false) {}
    Cat(std::string name) : Pet(name, false) {}
};
