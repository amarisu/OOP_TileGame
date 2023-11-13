#ifndef TILEGAME_GAMEFIELD_H
#define TILEGAME_GAMEFIELD_H

#define MIN_FIELD_SIZE 2
#define MAX_FIELD_SIZE 9

#include "FieldWrapper.h"
#include "Tile.h"
#include "Coordinates.h"

namespace TileGame {

    class GameField : public FieldWrapper{

    private:
        unsigned short width;
        unsigned short height;
        Tile** tiles;
        Coordinates startPoint;
        Coordinates destPoint;

        void setInitSize(unsigned short& dim, unsigned short value);
        void setPoints(Coordinates start, Coordinates dest);

    public:
        GameField(unsigned short w, unsigned short h,
                  Coordinates start, Coordinates end);
        GameField();
        ~GameField();
        GameField(const GameField& other);
        GameField(GameField&& other) noexcept ;
        GameField& operator=(const GameField& other) noexcept ;
        GameField& operator=(GameField&& other) noexcept ;


        unsigned short getHeight() override;
        unsigned short getWidth() override;
        bool getPassState(unsigned short x, unsigned short y) override;
        TileEvent* getEvent(unsigned short x, unsigned short y);
        Tile& getTile(unsigned short x, unsigned short y);

        const Coordinates& getDestPoint() override;
        const Coordinates& getStartPoint();

        void setStartEndEmpty();
    };
}

#endif //TILEGAME_GAMEFIELD_H
