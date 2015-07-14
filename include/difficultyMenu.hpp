#ifndef DIFFICULTYMENU_H
#define DIFFICULTYMENU_H

#include "state.hpp"
#include "button.hpp"
#include "playing.hpp"
#include "singlePlayerGame.hpp"

#include <SFML/Graphics.hpp>

class DifficultyMenu : public State{
    public:
        DifficultyMenu(Application* app);

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleEvent(sf::Event& event);

    private:

        sf::Text title;

        Button easyButton;
        Button mediumButton;
        Button hardButton;

        Button backButton;
        Button playButton;

        int selectedDifficulty = 0;
};

#endif // DIFFICULTYMENU_H
