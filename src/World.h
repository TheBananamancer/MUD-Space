#ifndef WORLD_H
#define WORLD_H

#include "PersistenceManager.h"

class World {
public:
    World();
    void update();
    void loadWorldState();
    void saveWorldState();

private:
    PersistenceManager persistence_manager_;
};

#endif
