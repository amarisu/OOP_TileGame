#ifndef TILEGAME_COMMAND_H
#define TILEGAME_COMMAND_H

#include "Enum_ExitCode.h"
#include "Enum_Commands.h"
#include <iostream>

namespace TileGame {

    class Controller;

    class Command {
    public:
        virtual ExitCode exec() = 0;
        virtual ~Command() = default;
    };

}

#endif //TILEGAME_COMMAND_H
