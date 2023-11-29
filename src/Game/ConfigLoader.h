#ifndef TILEGAME_CONFIGLOADER_H
#define TILEGAME_CONFIGLOADER_H

#include <map>
#include "Enum_InputObject.h"
#include "Command.h"

namespace TileGame {

    class ConfigLoader {

    public:
        virtual void readKeyConfig() = 0;

        virtual bool isConfigCorrect() const = 0;
        virtual InputObject getInputObject() = 0;
        virtual const std::map<int, Commands>& getKeys() = 0;

        virtual ~ConfigLoader() = default;

    };
}

#endif //TILEGAME_CONFIGLOADER_H
