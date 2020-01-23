#include "Engine.h"

void Engine::createGame()
{
    World* initWorld = new World(200, 50);
    Personality* initPersonality = new Personality();
    initPersonality->chooseTraits();
    gameLoop(initWorld, initPersonality);
}

void Engine::gameLoop(World* initWorld, Personality* initPersonality) {
    int count = 1;
    double time_counter = 0;
    clock_t this_time = clock();
    clock_t last_time = this_time;
    //std::cout << initPersonality->printLargestTrait();
    initWorld->assignGrid(initPersonality);
    while (true) {
        initWorld->printGrid();
        initWorld->evolve();
        system("CLS");
    }

    /*while (true)
    {
        this_time = clock();

        time_counter += (double)(this_time - last_time);

        last_time = this_time;

        if (time_counter > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
        {
            time_counter -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);
            printf("GENERATION %d\n", count);
            newWorld->printGrid();
            newWorld->evolve();
            count++;
        }
    }*/
}
