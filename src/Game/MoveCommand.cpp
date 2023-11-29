#include "MoveCommand.h"


namespace TileGame {

    ExitCode MoveCommand::exec() {

        ExitCode code = CONTINUE;

        std::cout << "\n";
        controller.step(direction);

        if(controller.checkNoHealth()){
            code = LOSE;
            std::cout << "\nGame over! You lost. Your score: " << controller.getCrystals() << "\n";
        }
        else if(controller.checkFinish()){
            code = WIN;
            std::cout << "\nLevel passed! Your score: " << controller.getCrystals() << "\n";
        }

        return code;
    }

    MoveCommand::MoveCommand(Controller& ctrl, Directions dir) : controller(ctrl),
                                                                 direction(dir) {}
}