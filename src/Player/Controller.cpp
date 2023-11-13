#include "Controller.h"


namespace TileGame {

    Controller::Controller(Player &player, FieldWrapper &field) :
            currentPlayer(player),
            currentField(field),
            currentPosition(0, 0) {}

    void Controller::changeHealthPoints(int change) {

        unsigned short curr_hp = currentPlayer.getHealthPoints();
        currentPlayer.setHealthPoints(curr_hp + change);
        //checkNoHealth();
    }

    void Controller::increaseCrystalPoints() {
        unsigned short curr_cp = currentPlayer.getCrystalPoints();
        currentPlayer.setCrystalPoints(curr_cp+1);
    }

    void Controller::step(Directions direction) {

        switch (direction) {
            case UP:
                setPosition(currentPosition.x, currentPosition.y + 1);
                break;

            case DOWN:
                setPosition(currentPosition.x, currentPosition.y - 1);
                break;

            case LEFT:
                setPosition(currentPosition.x - 1, currentPosition.y);
                break;

            case RIGHT:
                setPosition(currentPosition.x + 1, currentPosition.y);
                break;
        }
    }

    void Controller::setPosition(int x, int y) {

        if ( (x<0)  ||  x >= currentField.getWidth()
          || (y<0)  ||  y >= currentField.getHeight()
          || !currentField.getPassState(x, y))
          return;

        currentPosition.x = x;
        currentPosition.y = y;

        checkEvent(currentPosition);
    }

    Coordinates Controller::getPosition() { return currentPosition; }

    void Controller::checkEvent(const Coordinates& position) {

        TileEvent* currentEvent = currentField.getEvent(position.x, position.y);
        if(currentEvent != nullptr && currentEvent->isActive()){
            currentEvent->run(*this);
        }
    }

    bool Controller::checkFinish() { return currentPosition == currentField.getDestPoint(); }

    bool Controller::checkNoHealth() { return currentPlayer.getHealthPoints() == 0; }

    unsigned short Controller::getCrystals() { return currentPlayer.getCrystalPoints(); }

}