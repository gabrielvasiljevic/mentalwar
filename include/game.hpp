#ifndef GAME_H
#define GAME_H

#include "application.hpp"
#include "forceMeter.hpp"
#include "MindwaveModule.hpp"
#include <SFML/Graphics.hpp>

class Game{
    public:
        Game();
        ~Game();

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleEvent(sf::Event& event);

        void setApp(Application* app);

    private:
        //Focus Meter -> to the player, maybe
        //Signal Meter -> make it global

        //Rope
        //Music

    protected:
        Application* app;
        sf::Sprite background;
        ForceMeter forceMeter;
        bool gameover = false;
        sf::Clock updateClock;

        virtual void testGameover();

};

#endif // GAME_H
