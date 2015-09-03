#include "mainMenu.hpp"

MainMenu::MainMenu(Application* app) :  singlePlayerButton(336, 200, 128, 32, "Single Player"),
                                        multiPlayerButton(336, 250, 128, 32, "Multi Player"),
                                        optionsButton(336, 300, 128, 32, "Options"),
                                        exitButton(336, 350, 128, 32, "Exit"){
    this->app = app;

    title.setCharacterSize(48U);
    title.setColor(sf::Color::White);
    title.setFont(fontsDAO.getFont("agency_bold"));
    title.setPosition(312, 100);
    title.setString("Mental War");

    optionsButton.disable();
}

void MainMenu::draw(const float dt){
    app->window.draw(title);
    app->window.draw(singlePlayerButton);
    app->window.draw(multiPlayerButton);
    app->window.draw(optionsButton);
    app->window.draw(exitButton);
    return;
}

void MainMenu::handleEvent(sf::Event& event){
    switch(event.type){
        case sf::Event::Closed:
            app->window.close();
        break;

         case sf::Event::MouseButtonPressed: {

            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            if(singlePlayerButton.clicked(x, y)){
                app->pushState(new DifficultyMenu(app));
            }
            else if(multiPlayerButton.clicked(x, y)){
                app->pushState(new TeamsMenu(app));
            }
            else if(optionsButton.clicked(x, y)){

            }
            else if(exitButton.clicked(x, y)){
                app->window.close();
            }
            break;
        }

        case sf::Event::MouseMoved: {
            int x = event.mouseMove.x;
            int y = event.mouseMove.y;

            singlePlayerButton.hover(x, y);
            multiPlayerButton.hover(x, y);
            optionsButton.hover(x, y);
            exitButton.hover(x, y);

            break;
        }
    }
}

void MainMenu::update(const float dt){

}
