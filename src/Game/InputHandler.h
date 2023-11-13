#ifndef TILEGAME_INPUTHANDLER_H
#define TILEGAME_INPUTHANDLER_H

#include "Directions.h"
#include <map>

namespace TileGame {

    enum ExitCode{

        CONTINUE = 0,
        CANCEL,
        WIN,
        LOSE,
        CONFIG_ERROR,
        QUIT
    };

    enum Command {
        MOVE_UP = Directions::UP,
        MOVE_DOWN = Directions::DOWN,
        MOVE_LEFT = Directions::LEFT,
        MOVE_RIGHT = Directions::RIGHT,
        EXIT_GAME,
        CommandCount
    };

    class InputHandler{

    private:

        std::map<Command, int> vKeys;
        bool configCorrect = false;

    public:

        InputHandler();
        virtual void readKeyConfig(const char* path) = 0;
        virtual Command input() = 0;

        virtual bool isConfigCorrect();
    };

}

#endif //TILEGAME_INPUTHANDLER_H
