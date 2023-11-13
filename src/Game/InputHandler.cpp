#include "InputHandler.h"

namespace TileGame {

    void InputHandler::readKeyConfig(const char *path) {}
    Command InputHandler::input() {}

    bool InputHandler::isConfigCorrect() { return false; }

    InputHandler::InputHandler() {
        for(int i=0; i<CommandCount; i++){
            vKeys.insert(std::pair<Command, int>((Command)i,0));
        }
    }
}