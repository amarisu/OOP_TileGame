#ifndef TILEGAME_COMMANDHANDLER_H
#define TILEGAME_COMMANDHANDLER_H

#include "Controller.h"
#include "KeyboardInputHandler.h"


namespace TileGame {

    class CommandHandler {
    private:
        Controller& control;
    public:
        CommandHandler(Controller& controller);

        ExitCode process(Command command);
    };

}

#endif //TILEGAME_COMMANDHANDLER_H
