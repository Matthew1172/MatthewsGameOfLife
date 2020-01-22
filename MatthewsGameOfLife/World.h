#pragma once

#include "LifeCell.h"
#include <vector>
#include <iostream>

class World
{
public:
	World(const int x = 10, const int y = 10);
	void printGrid();
	void randGrid();
	void evolve();
	void applyLaw(int liveNeighbors, int x, int y);
	void birth(int liveNeighbors, int x, int y, Personality* thePersonality);
	void assignGrid(Personality* initPersonality);
private:
	std::vector< std::vector<LifeCell> > worldGrid;
};

