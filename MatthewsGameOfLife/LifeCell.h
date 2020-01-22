#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include "Personality.h"

class LifeCell
{
public:
	LifeCell(Personality* initPersonality = new Personality(), int initState = 0);
	char toString();
	void setState(int state);
	void setPersonality(Personality* newPersonality);
	Personality * getPersonality();
	int getState();
private:
	Personality* personality;
	int state;
};