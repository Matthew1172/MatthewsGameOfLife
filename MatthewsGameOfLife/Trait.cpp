#include "Trait.h"

Trait::Trait(std::string name, int value, char rep)
{
	this->name = name;
	this->value = value;
	this->rep = rep;
}

std::string Trait::getName()
{
	return name;
}

int Trait::getValue()
{
	return value;
}

char Trait::getRep()
{
	return rep;
}

void Trait::setValue(int newValue)
{
	value = newValue;
}
