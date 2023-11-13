#ifndef TILEGAME_CONTROLLER_H
#define TILEGAME_CONTROLLER_H

#include "Player.h"
#include "Directions.h"
#include "Coordinates.h"
#include "GameField.h"
#include "FieldLoader.h"
#include <iostream>

namespace TileGame {

    class Controller {

    private:

        Player &currentPlayer;
        FieldWrapper &currentField;
        Coordinates currentPosition;

        void checkEvent(const Coordinates& point);

    public:

        void changeHealthPoints(int change);
        void increaseCrystalPoints();
        void step(Directions direction);

        void setPosition(int x, int y);
        Coordinates getPosition();
        Controller(Player &player, FieldWrapper &field);

        bool checkNoHealth();
        bool checkFinish();

        unsigned short getCrystals();
    };

}

#endif //TILEGAME_CONTROLLER_H
