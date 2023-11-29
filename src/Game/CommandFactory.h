#ifndef TILEGAME_COMMANDFACTORY_H
#define TILEGAME_COMMANDFACTORY_H

#include "MoveCommand.h"
#include "ExitCommand.h"


namespace TileGame {

    class CommandFactory {
    private:
        Controller& controller;
    public:
        CommandFactory(Controller& controller);
        Command* createCommand(Commands cmdkey);
    };

}

#endif //TILEGAME_COMMANDFACTORY_H
