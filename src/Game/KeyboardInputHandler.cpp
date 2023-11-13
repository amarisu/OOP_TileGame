#include <conio.h>
#include "KeyboardInputHandler.h"

namespace TileGame {

    KeyboardInputHandler::KeyboardInputHandler() : InputHandler() {}

    Command KeyboardInputHandler::input() {

        while(true){

            //if(_kbhit()){
                for (auto i: vKeys) {
                    if (GetAsyncKeyState(i.second) == KEY_PRESSED)
                        return i.first;
                }
            //}
        }
    }

    //Command KeyboardInputHandler::getInput() { return currentInput; }

    void KeyboardInputHandler::readKeyConfig(const char* path) {

        std::ifstream config(path);

        if(!config.is_open()){
            configCorrect = false;
            return;
        }

        std::string buf;

        Command key;

        while(std::getline(config, buf, ' ')){

            key = (buf == "MOVE_UP") ? MOVE_UP :
                  (buf == "MOVE_DOWN") ? MOVE_DOWN :
                  (buf == "MOVE_LEFT") ? MOVE_LEFT :
                  (buf == "MOVE_RIGHT") ? MOVE_RIGHT :
                  (buf == "EXIT") ? EXIT_GAME : CommandCount;

            if(key == CommandCount){
                configCorrect = false;
                return;
            }

            std::getline(config, buf);

            if(buf.size() == 1)
                vKeys[key] = (isalpha(buf[0])) ?
                                    _toupper(buf[0])
                                           : buf[0];

            else{
                configCorrect = false;
                return;
            }
        }

        bool allCommandsConnected = true;

        std::set<int> values;

        for(auto i: vKeys){

            values.insert(i.second);
            allCommandsConnected = (bool) i.second;

            if(!allCommandsConnected)
                break;
        }

        allCommandsConnected &= ( values.size() == vKeys.size() );

        configCorrect = allCommandsConnected;
    }


    bool KeyboardInputHandler::isConfigCorrect() { return configCorrect; }


}
