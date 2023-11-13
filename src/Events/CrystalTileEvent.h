#ifndef TILEGAME_CRYSTALTILEEVENT_H
#define TILEGAME_CRYSTALTILEEVENT_H
#include "TileEvent.h"
#include "Controller.h"

namespace TileGame {

    class CrystalTileEvent : public TileEvent{
    private:
        bool active = true;
        void eventLog() override;
    public:
        void run(Controller& control) override;
        CrystalTileEvent* clone() override;
        bool isActive() override;
        void disable() override;
    };

}
#endif //TILEGAME_CRYSTALTILEEVENT_H
