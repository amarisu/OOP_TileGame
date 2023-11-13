#include "FireTileEvent.h"

namespace TileGame{

    void FireTileEvent::run(Controller& control){

        eventLog();
        if(hp_change < 0)
            control.changeHealthPoints(hp_change);

        // no disable!
    }

    bool FireTileEvent::isActive() { return true; }
    void FireTileEvent::disable() {}

    FireTileEvent *FireTileEvent::clone() {
        return new FireTileEvent(hp_change);
    }

    void FireTileEvent::eventLog() {
        std::cout << "Fire event occurred!\n";
    }

}