#ifndef TILEGAME_FILECONFIGLOADER_H
#define TILEGAME_FILECONFIGLOADER_H

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "ConfigLoader.h"

#define CONFIG_PATH "src/Game/input_configuration.txt"


namespace TileGame {

    class FileConfigLoader : public ConfigLoader {

    private:
        bool configCorrect = false;
        InputObject io = NONE;

        std::map<int, Commands> keys;

    public:
        void readKeyConfig() override;
        bool isConfigCorrect() const override;

        InputObject getInputObject() override;
        const std::map<int, Commands>& getKeys() override;

    };
}

#endif //TILEGAME_FILECONFIGLOADER_H
