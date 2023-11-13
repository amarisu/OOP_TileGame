cmake_minimum_required(VERSION 3.26)
project(TileGame)

set(CMAKE_CXX_STANDARD 20)

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
        src/Events/TileEvent.cpp
        src/Events/TeleportTileEvent.cpp
        src/Events/CrystalTileEvent.cpp
        src/Events/FireTileEvent.cpp
        src/Game/Game.cpp
        src/Game/Session.cpp
        src/Game/Session.h
        src/Game/KeyboardInputHandler.cpp
        src/Game/KeyboardInputHandler.h
        src/Game/CommandHandler.cpp
        src/Game/CommandHandler.h
        src/Game/InputHandler.cpp
        src/Game/InputHandler.h)