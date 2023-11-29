#ifndef TILEGAME_KEYBOARDINPUTHANDLER_H
#define TILEGAME_KEYBOARDINPUTHANDLER_H

#define KEY_PRESSED (-32767)

#include <windows.h>
#include <fstream>
#include "InputHandler.h"
#include "Command.h"



namespace TileGame {

    class KeyboardInputHandler : public InputHandler {

    private:

       const std::map<int, Commands>& keys;

    public:

        KeyboardInputHandler(const std::map<int, Commands>& keys);

        int input() override;
        const std::map<int, Commands>& getCommands() override;
    };

}

#endif //TILEGAME_KEYBOARDINPUTHANDLER_H
