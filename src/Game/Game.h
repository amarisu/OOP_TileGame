#ifndef TILEGAME_GAME_H
#define TILEGAME_GAME_H

#include "FieldLoader.h"
#include "Session.h"

#define NO_LEVEL 0
#define MAX_LEVEL (10)
#define LEVEL_DIR "levels"

namespace TileGame {

    class Game {

    private:

        FieldLoader gameLoader;
        int lastUnlockedLevel;
        unsigned short levelsCount;
        int currentLevel;

        void selectLevel();
        void unlockNextLevel();
        GameField getLevel();
        void resetLevel();

        ExitCode gameSession();

        void cancelConsoleEcho();

    public:
        Game();
        void exec();

    };
}

#endif //TILEGAME_GAME_H
