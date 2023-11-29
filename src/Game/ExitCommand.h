#ifndef TILEGAME_EXITCOMMAND_H
#define TILEGAME_EXITCOMMAND_H

#include "Command.h"


namespace TileGame {

    class ExitCommand : public Command  {

        ExitCode exec() override;
    };

}

#endif //TILEGAME_EXITCOMMAND_H
