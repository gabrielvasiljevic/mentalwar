#ifndef _PLAYING
#define _PLAYING

#include "state.hpp"
#include "game.hpp"

class Playing : public State{
    private:
        Application* app;
        Game* game;

    public:
        virtual void draw(const float dt);
        virtual void handleEvent(sf::Event& event);
        virtual void update(const float dt);

        Playing(Application* app, Game* game);
};

#endif // _PLAYING

