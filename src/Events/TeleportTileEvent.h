#ifndef TILEGAME_TELEPORTTILEEVENT_H
#define TILEGAME_TELEPORTTILEEVENT_H
#include "TileEvent.h"
#include "Controller.h"

namespace TileGame {

    class TeleportTileEvent : public TileEvent{
    private:
        Coordinates tpPoint;
        bool active;
        void eventLog() override;
    public:
        TeleportTileEvent(Coordinates point) : tpPoint(point), active(true){};
        void run(Controller& control) override;
        TeleportTileEvent* clone() override;
        bool isActive() override;
        void disable() override;
    };

}

#endif //TILEGAME_TELEPORTTILEEVENT_H
