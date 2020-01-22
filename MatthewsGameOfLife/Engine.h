#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "World.h"
#include "Trait.h"
#include "Personality.h"
class Engine
{
private:
	const int NUM_SECONDS = 1;
public:
	void createGame();
	void gameLoop(World* initWorld, Personality* initPersonality);
};

