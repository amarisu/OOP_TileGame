#include "CommandFactory.h"


namespace TileGame{

    Command* CommandFactory::createCommand(Commands cmdkey) {

        Command* cmd = nullptr;
        switch (cmdkey) {
            case MOVE_UP: case MOVE_DOWN: case MOVE_LEFT: case MOVE_RIGHT:
                cmd = new MoveCommand(controller, static_cast<Directions>(cmdkey));
                break;
            case EXIT_GAME:
                cmd = new ExitCommand();
                break;
            //default: exception
        }

        return cmd;
    }

    CommandFactory::CommandFactory(Controller& _controller) : controller(_controller) {}
}
