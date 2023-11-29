#include "Session.h"



namespace TileGame {

Session::Session(InputHandler& _inputHandler, GameField& level, int playerHealth)
                     : field(level),
                       player(playerHealth),
                       control(player, field),
                       inputHandler(_inputHandler),
                       endFlag(CONTINUE)
{

    CommandFactory factory(control);

    for (auto i : inputHandler.getCommands()){

        Command* cmd = factory.createCommand(i.second);
        commands.insert({i.first, cmd});
    }

}

    Session::~Session() {
        for (auto i : commands)
            delete i.second;
    }

    ExitCode Session::getExitCode() { return endFlag; }


    void Session::run() {

        int cmd;
        while(!endFlag){

            cmd = inputHandler.input();
            endFlag = commands[cmd]->exec();
            // здесь бы проверку смерти/выигрыша (вместо команд)

            // update();
        }

    }

}


    /*void Session::endGameSession(){

        switch(endFlag){
            case WIN:
                std::cout << "\nLevel passed! Your score: " << control.getCrystals() <<"\n";
                break;
            case CANCEL:

                break;
            case LOSE:
                std::cout << "\nGame over! You lost. Your score: " << control.getCrystals() <<"\n";
                break;
        }
    } */

