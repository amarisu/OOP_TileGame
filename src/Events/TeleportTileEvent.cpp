#include "TeleportTileEvent.h"

namespace TileGame {

    void TeleportTileEvent::run(Controller& control){

        eventLog();
        control.setPosition(tpPoint.x, tpPoint.y);
        disable();
    }

    bool TeleportTileEvent::isActive() { return active; }

    void TeleportTileEvent::disable() { active = false; }

    TeleportTileEvent *TeleportTileEvent::clone() {
        return new TeleportTileEvent(tpPoint);
    }

    void TeleportTileEvent::eventLog() {
        std::cout << "Teleport event occurred!\n";
    }

}