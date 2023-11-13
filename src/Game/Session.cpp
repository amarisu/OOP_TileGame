#include "Session.h"



namespace TileGame {

Session::Session(GameField& level, int playerHealth)
                     : field(level),
                       player(playerHealth),
                       control(player, field),
                       endFlag(CONTINUE) {}

    ExitCode Session::getExitCode() { return endFlag; }

    void Session::endGameSession(){

        switch(endFlag){
            case WIN:
                std::cout << "\nLevel passed! Your score: " << control.getCrystals() <<"\n";
                break;
            case CANCEL:
                std::cout << "\nBack to the main menu...\n";
                break;
            case LOSE:
                std::cout << "\nGame over! You lost. Your score: " << control.getCrystals() <<"\n";
                break;
        }
    }

void Session::run() {

        KeyboardInputHandler inputHandler;
        CommandHandler commandHandler(control);

        inputHandler.readKeyConfig("src/Game/input_configuration.txt");

        if(!inputHandler.isConfigCorrect()){
            endFlag = CONFIG_ERROR;
            return;
        }

        while(true){

            endFlag = commandHandler.process(inputHandler.input());
            if (endFlag){
                endGameSession();
                break;
            }
        }

    }
}