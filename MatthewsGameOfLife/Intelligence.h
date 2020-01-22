#pragma once
#include "Trait.h"
class Intelligence : public Trait
{
public:
	Intelligence(std::string name, int value, char rep) : Trait(name, value, rep) {};
};

