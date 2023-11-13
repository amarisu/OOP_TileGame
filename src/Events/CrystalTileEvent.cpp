#include "CrystalTileEvent.h"

namespace TileGame {

    void CrystalTileEvent::run(Controller& control){
        eventLog();
        control.increaseCrystalPoints();
        disable();
    }

    bool CrystalTileEvent::isActive() { return active; }

    void CrystalTileEvent::disable() { active = false; }

    CrystalTileEvent *CrystalTileEvent::clone() {
        return new CrystalTileEvent();
    }

    void CrystalTileEvent::eventLog() {
        std::cout << "Crystal event occurred!\n";
    }
}