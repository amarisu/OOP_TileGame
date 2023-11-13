#ifndef TILEGAME_TILE_H
#define TILEGAME_TILE_H

#include "TileEvent.h"
#include <iostream>

namespace TileGame {

    class Tile {
    private:
        bool passable;
        TileEvent* event;

    public:
        Tile(bool isPassable = true, TileEvent* event = nullptr);
        ~Tile();
        Tile(const Tile& other);
        Tile& operator=(const Tile& other);

        void setPassability(bool isPassable);
        bool getPassability();
        void setEvent(TileEvent* e);
        TileEvent* getEvent(); // возвращаемый тип?
    };

}

#endif //TILEGAME_TILE_H
