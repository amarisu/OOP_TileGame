#ifndef TILEGAME_KEYBOARDINPUTHANDLER_H
#define TILEGAME_KEYBOARDINPUTHANDLER_H

#define KEY_PRESSED (-32767)

#include <windows.h>
#include <fstream>
#include <map>
#include <set>
#include "InputHandler.h"


namespace TileGame {

    class KeyboardInputHandler : InputHandler {

    private:

        std::map<Command, int> vKeys;
        bool configCorrect = false;

    public:

        KeyboardInputHandler();
        void readKeyConfig(const char* path) override;
        bool isConfigCorrect() override;

        Command input();

    };

}

#endif //TILEGAME_KEYBOARDINPUTHANDLER_H
