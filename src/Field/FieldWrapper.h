#ifndef TILEGAME_FIELDWRAPPER_H
#define TILEGAME_FIELDWRAPPER_H

#include "TileEvent.h"
#include "Coordinates.h"

namespace TileGame {

    class FieldWrapper {
    public:
        virtual const Coordinates& getDestPoint();
        virtual bool getPassState(unsigned short x, unsigned short y);
        virtual TileEvent* getEvent(unsigned short x, unsigned short y);
        virtual unsigned short getHeight();
        virtual unsigned short getWidth();
    };

}

#endif //TILEGAME_FIELDWRAPPER_H
