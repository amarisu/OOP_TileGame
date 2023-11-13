#ifndef TILEGAME_COORDINATES_H
#define TILEGAME_COORDINATES_H

namespace TileGame {
    struct Coordinates{

        int x;
        int y;

        Coordinates() = default;
        Coordinates(int _x, int _y) : x(_x), y(_y){}
        bool operator== (const Coordinates &c) { return (c.x == this->x && c.y == this->y); };
        bool operator!= (const Coordinates &c) { return (c.x != this->x || c.y != this->y); };  // 11/10
    };

}


#endif //TILEGAME_COORDINATES_H
