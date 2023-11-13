#include "Player.h"


namespace TileGame {

    Player::Player(int health) : crystalPoints(0)
    {
        setHealthPoints(health);
    }

    void Player::setHealthPoints(int health) {

        if(health < 0)  healthPoints = 0;
        else if (health > MAX_HEALTH)  healthPoints = MAX_HEALTH;

        else healthPoints = health;
    }

    void Player::setCrystalPoints(unsigned int crystals) {

        crystalPoints = (crystals > MAX_CRYSTALS) ? crystalPoints : crystals;
    }

    unsigned short Player::getHealthPoints() { return healthPoints; }

    unsigned short Player::getCrystalPoints() { return crystalPoints; }

}