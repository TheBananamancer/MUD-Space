#include "World.h"

World::World() : persistence_manager_("world.dat") {}

void World::update()
{
    saveWorldState();
}

void World::loadWorldState()
{
    persistence_manager_.loadWorldState();
}

void World::saveWorldState()
{
    persistence_manager_.saveWorldState();
}
