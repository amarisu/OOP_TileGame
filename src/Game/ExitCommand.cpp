#include "ExitCommand.h"

namespace TileGame {

    ExitCode ExitCommand::exec() {

        std::cout << "\nBack to the main menu...\n";
        return CANCEL;
    }

}