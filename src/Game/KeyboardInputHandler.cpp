#include <conio.h>
#include "KeyboardInputHandler.h"

namespace TileGame {

    KeyboardInputHandler::KeyboardInputHandler(const std::map<int, Commands> &_keys) : keys(_keys) {}

    int KeyboardInputHandler::input() {

        int c;

        while (true) {

            /*c = _getch();
            if (keys.find(c) != keys.end())
                return c;
            */

            for (auto i: keys) {
                if (GetAsyncKeyState(i.first) == KEY_PRESSED)
                    return i.first;
            }
        }
    }

    const std::map<int, Commands> &KeyboardInputHandler::getCommands() { return keys; }
}