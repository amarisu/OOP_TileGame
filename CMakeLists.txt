cmake_minimum_required(VERSION 3.26)
project(TileGame)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(src/Player)
include_directories(src/Events)
include_directories(src/Field)
include_directories(src/Game)
add_executable( TileGame src/main.cpp
        src/Player/Controller.cpp
        src/Player/Player.cpp
        src/Field/Tile.cpp
        src/Field/GameField.cpp
        src/Field/FieldWrapper.cpp
        src/Field/FieldLoader.cpp
        src/Events/TeleportTileEvent.cpp
        src/Events/CrystalTileEvent.cpp
        src/Events/FireTileEvent.cpp
        src/Game/Game.cpp
        src/Game/Session.cpp
        src/Game/Session.h
        src/Game/KeyboardInputHandler.cpp
        src/Game/KeyboardInputHandler.h
        src/Game/InputHandler.h
        src/Game/Command.h
        src/Game/MoveCommand.cpp
        src/Game/MoveCommand.h
        src/Game/FileConfigLoader.cpp
        src/Game/FileConfigLoader.h
        src/Game/ConfigLoader.h
        src/Game/CommandFactory.h
        src/Game/ExitCommand.cpp
        src/Game/ExitCommand.h
        src/Game/CommandFactory.cpp
        src/Game/Enum_InputObject.h
        src/Game/Enum_Commands.h
        src/Game/Enum_ExitCode.h)