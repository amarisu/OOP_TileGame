#ifndef TILEGAME_FIELDLOADER_H
#define TILEGAME_FIELDLOADER_H

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <ctime>
#include <filesystem>
#include "GameField.h"
#include "FireTileEvent.h"
#include "CrystalTileEvent.h"
#include "TeleportTileEvent.h"

namespace fs = std::filesystem;

namespace TileGame {

    enum events {
        NO_EVENT,
        CRYSTAL_EVENT,
        FIRE_EVENT,
        TELEPORT_EVENT
    };

    class FieldLoader {
    private:
        fs::path dir;

        std::vector<GameField> levels;
        int levelCount;


        bool loadField(const fs::path& filepath);

    public:
        FieldLoader(fs::path directory);
        void load();

        int getLevelCount() const;
        GameField getField(int pos);

    };




}


#endif //TILEGAME_FIELDLOADER_H
