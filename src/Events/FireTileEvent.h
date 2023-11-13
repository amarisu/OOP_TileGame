#ifndef TILEGAME_FIRETILEEVENT_H
#define TILEGAME_FIRETILEEVENT_H
#include "TileEvent.h"
#include "Controller.h"

namespace TileGame{

    class FireTileEvent : public TileEvent{
        int hp_change;
        void eventLog() override;
    public:
        void run(Controller& control);
        FireTileEvent(int change) : hp_change(change){};
        FireTileEvent* clone() override;
        bool isActive() override;
        void disable() override;


    };

}

#endif //TILEGAME_FIRETILEEVENT_H
