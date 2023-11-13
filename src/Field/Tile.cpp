#include "Tile.h"

namespace TileGame {

    Tile::Tile(bool isPassable, TileEvent* ev) : event(ev) { setPassability(isPassable); }

    void Tile::setPassability(bool isPassable) { passable = isPassable; }

    Tile::~Tile() {
        delete event;       // ?
    }

    Tile::Tile(const Tile &other) : passable(other.passable) {
        if (other.event != nullptr)
            event = other.event->clone();
        else
            event = nullptr;
    }

    Tile &Tile::operator=(const Tile &other){
        Tile tmp(other);
        std::swap(passable, tmp.passable);
        std::swap(event, tmp.event);
        return *this;
    }

    bool Tile::getPassability() { return passable; }

    void Tile::setEvent(TileEvent* e) {

        delete event;

        if(getPassability()){
            event = e;
        }

    }

    TileEvent *Tile::getEvent() { return event; }

}