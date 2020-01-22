#include "World.h"

World::World(const int x, const int y)
{
	std::vector< std::vector<LifeCell> > grid(y, std::vector<LifeCell> (x) );
	worldGrid = grid;
}

void World::printGrid()
{
	for(std::vector<LifeCell> row : worldGrid)
	{
		for(LifeCell col : row){
			std::cout << col.toString();
		}
		std::cout << "\n";
	}
}

void World::randGrid()
{
	int r;
	srand(time(0));
	for (int i = 0; i < worldGrid.size(); i++) {
		for (int j = 0; j < worldGrid[i].size(); j++) {
			r = rand()%2;
			//worldGrid[i][j].setState(r);
		}
	}
}

void World::assignGrid(Personality* initPersonality)
{
	int r;
	srand(time(0));
	for (int i = 0; i < worldGrid.size(); i++) {
		for (int j = 0; j < worldGrid[i].size(); j++) {
			r = rand() % 2;
			worldGrid[i][j].setState(r);
			worldGrid[i][j].setPersonality(initPersonality);
		}
	}
}

void World::evolve() {
	std::vector< std::vector<LifeCell> > nextWorld;
	nextWorld = worldGrid;
	for (int x = 1; x < worldGrid.size()-1; x++) {
		for (int y = 1; y < worldGrid[x].size()-1; y++) {
			int life = 0;
			Personality* thePersonality = new Personality();
			for (int c = -1; c < 2; c++) {
				for (int d = -1; d < 2; d++) {
					if (!(c == 0 && d == 0)) {
						if (nextWorld[x + c][y + d].getState() == 1) {
							thePersonality = nextWorld[x + c][y + d].getPersonality();
							thePersonality = thePersonality->scramble(thePersonality);
							life++;
						}
					}
				}
			}
			//applyLaw(life, x, y);
			birth(life, x, y, thePersonality);
		}
	}
}

void World::applyLaw(int liveNeighbors, int x, int y) {
	if (liveNeighbors < 2) { worldGrid[x][y].setState(false); }
	else if (liveNeighbors == 3) { worldGrid[x][y].setState(true); }
	else if (liveNeighbors > 3) { worldGrid[x][y].setState(false); }
}

void World::birth(int liveNeighbors, int x, int y, Personality* thePersonality)
{
	if (liveNeighbors < 2) {
		worldGrid[x][y].setState(false);
	}
	else if (liveNeighbors == 3) {
		worldGrid[x][y].setState(true);
		worldGrid[x][y].setPersonality(thePersonality);
	}
	else if (liveNeighbors > 3) {
		worldGrid[x][y].setState(false);
	}
}

