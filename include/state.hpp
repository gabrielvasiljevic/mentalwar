#ifndef _STATE
#define _STATE

#include "application.hpp"

class Application;

class State{
    public:

        Application* app;

        virtual void draw(const float dt) = 0;
        virtual void update(const float dt) = 0;
        virtual void handleEvent(sf::Event& event) = 0;
};

#endif /* _STATE */
