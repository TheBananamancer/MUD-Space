#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Room.h"

class Player {
public:
    std::string name;
    Room* currentRoom;
};

#endif
