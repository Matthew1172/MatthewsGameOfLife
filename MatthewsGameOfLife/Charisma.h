#pragma once
#include "Trait.h"
class Charisma : public Trait
{
public:
	Charisma(std::string name, int value, char rep) : Trait(name, value, rep) {};
};

