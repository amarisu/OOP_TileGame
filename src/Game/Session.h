#ifndef TILEGAME_SESSION_H
#define TILEGAME_SESSION_H

#include "Controller.h"
#include "KeyboardInputHandler.h"
#include "CommandFactory.h"
#include <windows.h>

namespace TileGame {

    class Session {

    private:

        Player player;
        GameField& field;
        Controller control;

        InputHandler& inputHandler;
        ExitCode endFlag;

        std::map<int, Command*> commands;

        //void endGameSession();

    public:
        Session(InputHandler& _inputHandler, GameField& level, int playerHealth);
        ~Session();
        void run();

        ExitCode getExitCode();
    };

}

#endif //TILEGAME_SESSION_H
