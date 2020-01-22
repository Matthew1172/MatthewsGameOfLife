#pragma once
#include "Trait.h"
class Strength : public Trait
{
public:
	Strength(std::string name, int value, char rep) : Trait(name, value, rep) {};
};

