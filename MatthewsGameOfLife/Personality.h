#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include "Trait.h"
#include "Strength.h"
#include "Intelligence.h"
#include "Charisma.h"
class Personality
{
private:
	std::vector<std::unique_ptr<Trait>> traits;
public:
	Personality();
	void chooseTraits();
	char printLargestTrait();
	std::vector<std::unique_ptr<Trait>>* getTraits();
	Personality* scramble(Personality* thePersonality);
};

