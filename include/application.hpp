#ifndef _APP
#define _APP

#include <stack>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "global.hpp"

class State;

class Application{
    public:

    std::stack<State*> states;

    sf::RenderWindow window;

    void pushState(State* state);
    void popState();
    void changeState(State* state);
    State* peekState();

    void mainLoop();
    //void keepAlive();
    //void handleEvent(sf::Event& event);
    void draw();
    //void setConnected(int con);
    void takeScreenshot();

    Application();
    ~Application();

    private:
        /*int connected;
        sf::Text globalWarning;

        sf::Clock keepAliveClock;
        sf::Clock globalWarningClock;

        ConfigurationPanel confPanel;*/
};
#endif // _APP
