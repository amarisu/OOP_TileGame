#ifndef TILEGAME_SESSION_H
#define TILEGAME_SESSION_H

#include "Controller.h"
#include "KeyboardInputHandler.h"
#include "CommandHandler.h"
#include <windows.h>

namespace TileGame {

    class Session {

    private:

        Player player;
        GameField& field;
        Controller control;

        ExitCode endFlag;

    public:
        Session(GameField& level, int playerHealth);
        void run();

        ExitCode getExitCode();

        void endGameSession();
    };

}

#endif //TILEGAME_SESSION_H
