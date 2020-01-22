#include "LifeCell.h"

LifeCell::LifeCell(Personality* initPersonality, int initState)
{
	state = initState;
	personality = initPersonality;
}

char LifeCell::toString()
{
	char personalityTraitLetter = ' ';
	switch (state) {
	case 0:
		break;
	case 1:
		personalityTraitLetter = personality->printLargestTrait();
		break;
	}
	return personalityTraitLetter;
}

void LifeCell::setPersonality(Personality* newPersonality)
{
	personality = newPersonality;
}

void LifeCell::setState(int newState)
{
	state = newState;
}

Personality * LifeCell::getPersonality()
{
	return personality;
}

int LifeCell::getState()
{
	return state;
}