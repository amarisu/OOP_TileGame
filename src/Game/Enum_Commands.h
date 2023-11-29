#ifndef TILEGAME_ENUM_COMMANDS_H
#define TILEGAME_ENUM_COMMANDS_H

#include "Directions.h"

namespace TileGame{

    enum Commands {
        MOVE_UP = Directions::UP,
        MOVE_DOWN = Directions::DOWN,
        MOVE_LEFT = Directions::LEFT,
        MOVE_RIGHT = Directions::RIGHT,
        EXIT_GAME,
        CommandCount
    };
}


#endif //TILEGAME_ENUM_COMMANDS_H
