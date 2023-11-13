#ifndef TILEGAME_PLAYER_H
#define TILEGAME_PLAYER_H

#define MAX_HEALTH 10
#define BASE_HEALTH 5
#define MAX_CRYSTALS 10


namespace TileGame {

    class Player {

    private:

        unsigned short healthPoints;
        unsigned short crystalPoints;

    public:

        Player(int health);

        void setHealthPoints(int health);
        void setCrystalPoints(unsigned int crystals);

        unsigned short getHealthPoints();
        unsigned short getCrystalPoints();

    };

}


#endif //TILEGAME_PLAYER_H
