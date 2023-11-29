#ifndef TILEGAME_MOVECOMMAND_H
#define TILEGAME_MOVECOMMAND_H

#include "Command.h"
#include "Controller.h"
#include "Directions.h"

namespace TileGame {

    class MoveCommand : public Command {
    private:
        Directions direction;
        Controller& controller;

    public:
        MoveCommand(Controller& ctrl, Directions dir);
        ExitCode exec() override;

    };

}

#endif //TILEGAME_MOVECOMMAND_H
