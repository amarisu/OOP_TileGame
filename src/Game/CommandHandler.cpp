#include "CommandHandler.h"

namespace TileGame {

    CommandHandler::CommandHandler(Controller& controller) : control(controller){}

    ExitCode CommandHandler::process(Command command) {

        ExitCode code = CONTINUE;
        switch(command){

            case MOVE_UP:
                std::cout << "\nstep: UP\n";
                control.step(UP);
                break;

            case MOVE_DOWN:
                std::cout << "\nstep: DOWN\n";
                control.step(DOWN);
                break;

            case MOVE_LEFT:
                std::cout << "\nstep: LEFT\n";
                control.step(LEFT);
                break;

            case MOVE_RIGHT:
                std::cout << "\nstep: RIGHT\n";
                control.step(RIGHT);
                break;

            case EXIT_GAME:
                return CANCEL;

            default:
                break;
        }

        code = (control.checkNoHealth()) ? LOSE
             : (control.checkFinish()) ? WIN
             : code;

        return code;
    }

}