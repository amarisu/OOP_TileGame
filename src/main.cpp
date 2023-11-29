#include "Game.h"

int main() {

    TileGame::ConfigLoader* configLoader = new TileGame::FileConfigLoader();
    configLoader->readKeyConfig();

    if(configLoader->isConfigCorrect()){
        TileGame::Game game(*configLoader);
        game.exec();
    }
    else std::cout <<"There are some configuration issues. Fix it and try again.\n";

    delete configLoader; //
    return 0;
}
