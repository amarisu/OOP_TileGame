#include "FieldLoader.h"

#include <utility>

namespace TileGame {

    FieldLoader::FieldLoader(fs::path directory) : levelCount{},
                                 dir(std::move(directory))
    {
        levels.reserve(10);
    }

    bool FieldLoader::loadField(const fs::path& filepath) {

        std::ifstream lvlfile(filepath);

        if (!lvlfile.is_open()) {
            std::cout << "Level file " << filepath << " can\'t be opened.\n";       // log-like
            return false;
        }

        int field_width{MIN_FIELD_SIZE};
        int field_height{MIN_FIELD_SIZE};

        std::regex reg_firstLine(R"([2-9] [2-9])");
        std::string cmpLine;
        std::getline(lvlfile, cmpLine);

        if (std::regex_match(cmpLine, reg_firstLine)) {
            std::istringstream cmpLineStream(cmpLine);
            cmpLineStream >> field_width >> field_height;
        }
        else return false;

        GameField field(field_width, field_height, {0,0}, {field_width-1, field_height-1});

        std::regex reg_lines("[0-" + std::to_string(field_width-1)
                             +"] [0-" + std::to_string(field_height-1)
                             + "] [0-1] [0-3]");


        while(std::getline(lvlfile, cmpLine)){

            if(! std::regex_match(cmpLine, reg_lines) && !cmpLine.empty())
                return false;


            std::istringstream cmpStream(cmpLine);
            int x{};
            int y{};
            bool passable;
            int event;
            cmpStream >> x >> y >> passable;
            cmpStream >> event;

            Tile &currentTile = field.getTile(x,y);
            currentTile.setPassability(passable);

            switch (event) {
                case NO_EVENT:
                    currentTile.setEvent(nullptr);
                    break;
                case CRYSTAL_EVENT:
                    currentTile.setEvent(new CrystalTileEvent());
                    break;
                case FIRE_EVENT:
                    currentTile.setEvent(new FireTileEvent(-2));
                    break;
                case TELEPORT_EVENT:
                    srand(time(nullptr));
                    currentTile.setEvent(new TeleportTileEvent({rand()%field_width,rand()%field_height}));
                    break;
            }
        }

        field.setStartEndEmpty();

        levels.push_back(field);
        levelCount++;

        lvlfile.close();
        return true;
    }


    GameField FieldLoader::getField(int pos) { return levels[pos]; }

    int FieldLoader::getLevelCount() const { return levelCount; }


    void FieldLoader::load() {

        for(const auto& file : fs::directory_iterator(dir)){

            loadField(file);

        }
    }


}