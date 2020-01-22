#pragma once
#include <string>
class Trait
{
private:
	std::string name;
	int value;
	char rep;
public:
	Trait(std::string name, int value, char rep);
	virtual std::string getName();
	virtual int getValue();
	virtual char getRep();
	virtual void setValue(int newValue);
	//void setName(std::string newName);
	//void setRep(char newRep);
};