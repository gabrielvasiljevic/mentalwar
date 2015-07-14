#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "state.hpp"
#include "button.hpp"
#include "difficultyMenu.hpp"

#include <SFML/Graphics.hpp>

class MainMenu : public State {
    public:
        MainMenu(Application* app);

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleEvent(sf::Event& event);

    private:
        sf::Text title;

        Button singlePlayerButton;

        Button multiPlayerButton;

        Button optionsButton;

        Button exitButton;


};

#endif // MAINMENU_HPP
