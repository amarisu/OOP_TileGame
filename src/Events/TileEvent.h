#ifndef TILEGAME_TILEEVENT_H
#define TILEGAME_TILEEVENT_H



namespace TileGame {
    class Controller;

    class TileEvent {
    public:
        virtual void eventLog() = 0;
        ~TileEvent() = default;
        virtual TileEvent* clone() = 0;
        virtual void run(Controller& control) = 0;
        virtual bool isActive() = 0;
        virtual void disable() = 0;
    };

}

#endif //TILEGAME_TILEEVENT_H
