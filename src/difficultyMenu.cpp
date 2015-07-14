#include "difficultyMenu.hpp"

DifficultyMenu::DifficultyMenu(Application* app):   easyButton(336, 200, 128, 32, "Easy"),
                                                    mediumButton(336, 250, 128, 32, "Medium"),
                                                    hardButton(336, 300, 128, 32, "Hard"),
                                                    backButton(300, 350, 96, 32, "Back"),
                                                    playButton(400, 350, 96, 32, "Play!"){
    this->app = app;

    title.setCharacterSize(48U);
    title.setColor(sf::Color::White);
    title.setFont(fontsDAO.getFont("agency_bold"));
    title.setPosition(312, 100);
    title.setString("Difficulty");

    easyButton.setColor(sf::Color::Green);
    easyButton.disableHover();

    mediumButton.setColor(sf::Color::Yellow);
    mediumButton.disableHover();

    hardButton.setColor(sf::Color::Red);
    hardButton.disableHover();
}

void DifficultyMenu::draw(const float dt){
    app->window.draw(title);
    app->window.draw(easyButton);
    app->window.draw(mediumButton);
    app->window.draw(hardButton);
    app->window.draw(backButton);
    app->window.draw(playButton);
    return;
}

void DifficultyMenu::update(const float dt){

}

void DifficultyMenu::handleEvent(sf::Event& event){
    switch(event.type){
        case sf::Event::Closed:
            app->window.close();
        break;

         case sf::Event::MouseButtonPressed: {

            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            if(easyButton.clicked(x, y)){
                selectedDifficulty = 0;
            }
            else if(mediumButton.clicked(x, y)){
                selectedDifficulty = 1;
            }
            else if(hardButton.clicked(x, y)){
                selectedDifficulty = 2;
            }
            else if(backButton.clicked(x, y)){
                app->popState();
            }
            else if(playButton.clicked(x, y)){
                app->pushState(new Playing(app, new SinglePlayerGame(selectedDifficulty)));
            }
            break;
        }

        case sf::Event::MouseMoved: {
            int x = event.mouseMove.x;
            int y = event.mouseMove.y;

            easyButton.hover(x, y);
            mediumButton.hover(x, y);
            hardButton.hover(x, y);
            backButton.hover(x, y);
            playButton.hover(x, y);

            break;
        }
    }
}
