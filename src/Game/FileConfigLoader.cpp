#include <set>
#include "FileConfigLoader.h"

namespace TileGame {


    void FileConfigLoader::readKeyConfig() {

        std::ifstream config(CONFIG_PATH);

        if(!config.is_open()){
            configCorrect = false;
            return;
        }

        std::string buf;

        std::getline(config, buf);
        if(buf == "INPUT=KEYBOARD")
            io = KEYBOARD;

        if(!io){
            configCorrect = false;
            return;
        }

        Commands cmd;

        while(std::getline(config, buf, ' ')){

            cmd = (buf == "MOVE_UP") ? MOVE_UP :
                  (buf == "MOVE_DOWN") ? MOVE_DOWN :
                  (buf == "MOVE_LEFT") ? MOVE_LEFT :
                  (buf == "MOVE_RIGHT") ? MOVE_RIGHT :
                  (buf == "EXIT") ? EXIT_GAME : CommandCount;

            if(cmd == CommandCount){
                configCorrect = false;
                return;
            }

            std::getline(config, buf);

            if(buf.size() == 1){

                char key = (isalpha(buf[0]))
                           ? _toupper(buf[0])
                           : buf[0];

                keys.insert({key, cmd});        // одна команда не может быть назначена на несколько клавиш
            }
            else{
                configCorrect = false;
                return;
            }
        }

        std::set<Commands> values;
        for(auto i: keys){ values.insert(i.second); }

        if(values.size() == keys.size() && CommandCount == keys.size())
            configCorrect = true;
    }


    bool FileConfigLoader::isConfigCorrect() const { return configCorrect; }


    InputObject FileConfigLoader::getInputObject() { return io; }


    const std::map<int, Commands> &FileConfigLoader::getKeys() { return keys; }  // вызывается в условии isConfigCorrect

}