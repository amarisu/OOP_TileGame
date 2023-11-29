#ifndef TILEGAME_INPUTHANDLER_H
#define TILEGAME_INPUTHANDLER_H

#include "Directions.h"
#include "CommandFactory.h"
#include <map>

namespace TileGame {


    class InputHandler{

    public:
        virtual ~InputHandler() = default;
        virtual int input() = 0;
        virtual const std::map<int, Commands>& getCommands() = 0;
    };

}

#endif //TILEGAME_INPUTHANDLER_H
