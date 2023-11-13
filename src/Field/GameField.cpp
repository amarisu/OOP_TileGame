#include "GameField.h"
#include <iostream>

namespace TileGame {

    GameField::GameField(unsigned short w, unsigned short h,
                         Coordinates start, Coordinates end)
    {
        setInitSize(width, w);
        setInitSize(height, h);

        tiles = new Tile*[h];

        for(int i=0; i<h; i++)
            tiles[i] = new Tile[w];

        setPoints(start, end);

    }

    GameField::GameField() : GameField(MIN_FIELD_SIZE, MIN_FIELD_SIZE,
                                       {0,0},
                                       {MIN_FIELD_SIZE-1, MIN_FIELD_SIZE-1}) {};


    GameField::~GameField() {

        for(int i=0; i<height; i++){
            delete[] tiles[i];
        }
        delete[] tiles;
    }


    void GameField::setPoints(Coordinates start, Coordinates dest) {

        unsigned short start_x;
        unsigned short start_y;
        unsigned short end_x;
        unsigned short end_y;


               /// в функцию checkPoint(
        if(start.x < 0)
            start_x = 0;
        else if(start.x > width-1)
            start_x = width-1;
        else start_x = start.x;


        if(start.y < 0)
            start_y = 0;
        else if(start.y > height-1)
            start_y = width-1;
        else start_y = start.y;


        if(dest.x < 0)
            end_x = 0;
        else if(dest.x > width-1)
            end_x = width-1;
        else end_x = dest.x;


        if(start.y < 0)
            end_y = 0;
        else if(dest.y > height-1)
            end_y = width-1;
        else end_y = dest.y;

        startPoint.x = start_x;
        startPoint.y = start_y;
        destPoint.x = end_x;
        destPoint.y = end_y;

        if(start.x == dest.x && start.y == dest.y) {
            startPoint = {0, 0};
            destPoint = {width-1, height-1};
        }


    }

    void GameField::setStartEndEmpty(){

        auto start = getTile(startPoint.x, startPoint.y);
        auto end = getTile(destPoint.x, destPoint.y);

        start.setPassability(true);
        if(start.getEvent() != nullptr)
            start.getEvent()->disable();

        end.setPassability(true);
        if(end.getEvent() != nullptr)
            end.getEvent()->disable();
    }

    void GameField::setInitSize(unsigned short &dim, unsigned short value) {

        if(value < MIN_FIELD_SIZE)
            dim = MIN_FIELD_SIZE;

        else if(value > MAX_FIELD_SIZE)
            dim = MAX_FIELD_SIZE;

        else dim = value;
    }

    GameField::GameField(const GameField &other) :  width(other.width),
                                                    height(other.height),
                                                    startPoint(other.startPoint),
                                                    destPoint(other.destPoint)
    {
        tiles = new Tile*[other.height];

        for(int i=0; i<other.height; i++) {

            tiles[i] = new Tile[other.width];
            for(int j=0; j<other.width; j++){
                tiles[i][j] = other.tiles[i][j];
            }
        }
    }


    GameField::GameField(GameField &&other) noexcept : height(0),
                                              width(0),
                                              startPoint(0,0),
                                              destPoint(0,0),
                                              tiles(nullptr)
    {
        std::swap(height, other.height);
        std::swap(width, other.width);
        std::swap(startPoint, other.startPoint);
        std::swap(destPoint, other.destPoint);
        std::swap(tiles, other.tiles);
    }

    GameField &GameField::operator=(GameField &&other) noexcept {
        if(this != &other) {
            std::swap(height, other.height);
            std::swap(width, other.width);
            std::swap(startPoint, other.startPoint);
            std::swap(destPoint, other.destPoint);
            std::swap(tiles, other.tiles);
        }
        return *this;
    }

    GameField &GameField::operator=(const GameField &other) noexcept {

        GameField tmp(other);
        std::swap(height, tmp.height);
        std::swap(width, tmp.width);
        std::swap(startPoint, tmp.startPoint);
        std::swap(destPoint, tmp.destPoint);
        std::swap(tiles, tmp.tiles);

        return *this;
    }

    unsigned short GameField::getHeight() { return height; }

    unsigned short GameField::getWidth() { return width; }

    bool GameField::getPassState(unsigned short x, unsigned short y) { return getTile(x, y).getPassability(); }

    TileEvent* GameField::getEvent(unsigned short x, unsigned short y) { return getTile(x, y).getEvent(); }

    const Coordinates& GameField::getStartPoint() { return startPoint; }

    const Coordinates& GameField::getDestPoint() { return destPoint; }

    Tile &GameField::getTile(unsigned short x, unsigned short y) {
        return tiles[height-y-1][x];
    }

}