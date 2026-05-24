#include "Game.h"
#include "World.h"

void Game::run()
{
    world_.loadWorldState();
    while (true) {
        world_.update();
    }
}
