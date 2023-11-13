#include "Game.h"



namespace TileGame {


    Game::Game() : lastUnlockedLevel(NO_LEVEL),
                   currentLevel(NO_LEVEL),
                   gameLoader(LEVEL_DIR) {}


    void Game::unlockNextLevel() { if(lastUnlockedLevel < levelsCount) lastUnlockedLevel += 1; }

    GameField Game::getLevel(){ return gameLoader.getField(currentLevel-1); }

    void Game::resetLevel() { currentLevel = NO_LEVEL; }

    void Game::selectLevel() {

        int level{};

        while(level < 1 || level > lastUnlockedLevel) {

            std::cout <<"Select a level. Unlocked levels: ";
            for(int i=1; i<=lastUnlockedLevel; i++)
                std::cout <<i << " ";

            std::cout <<"\n >>";

            std::string buf;
            std::getline(std::cin, buf);

            if (buf == "quit"){
                currentLevel =  NO_LEVEL; // а вообще подтверждение выхода - и не здесь */
                return;
            }

            else if(isdigit(buf[0]))
                level = std::stoi(buf);

            if(level < 1 || level > lastUnlockedLevel){
                std::cout << "There is no such level for you here! Choose another one.\n\n";
            }

        }
        currentLevel = level;
    }

    ExitCode Game::gameSession(){

        selectLevel();
        if(currentLevel == NO_LEVEL) return QUIT;

        GameField level(getLevel());
        Session currentGame(level, BASE_HEALTH);

        std::cout << "\nStarting the game session...\n";
        currentGame.run(); // бесконечный цикл внутри!

        resetLevel();
        return currentGame.getExitCode();
    }

    void Game::exec() {

        gameLoader.load();
        levelsCount = gameLoader.getLevelCount();

        if(levelsCount == 0) {
            std::cout << "No levels found. Please restart the game with some correct lvl-files inside the \""
                      << LEVEL_DIR << "\" directory.\n";
            return;
        }
        unlockNextLevel();

        while(true){
            ExitCode sessionResult = gameSession();

            if (sessionResult == WIN) unlockNextLevel();
            else if(sessionResult == CONFIG_ERROR) { std::cout <<"There are some configuration issues. Fix it and try again.\n"; break; }
            else if(sessionResult == QUIT) { std::cout <<"Quitting the game.\n"; break; }
        }

    }

    void Game::cancelConsoleEcho() {

    #ifdef WIN32
        HANDLE console = GetStdHandle(STD_INPUT_HANDLE);

        DWORD mode;
        GetConsoleMode(console, &mode);
        SetConsoleMode(console, mode & ~ENABLE_ECHO_INPUT);
    #else
        //system("stty -echo");
    #endif
    }


}