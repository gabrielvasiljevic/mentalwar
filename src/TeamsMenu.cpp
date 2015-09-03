#include "TeamsMenu.hpp"

TeamsMenu::TeamsMenu(Application* app) : backButton(300, 350, 96, 32, "Back"),
                                         playButton(400, 350, 96, 32, "Play!"){
    this->app = app;

    versusText.setFont(fontsDAO.getFont("agency_bold"));
    versusText.setCharacterSize(20U);
    versusText.setColor(sf::Color::White);
    versusText.setPosition(312, 100);
    versusText.setString("VS");
}

TeamsMenu::~TeamsMenu(){
    //dtor
}

void TeamsMenu::draw(const float dt){
    app->window.draw(backButton);
    app->window.draw(playButton);
    app->window.draw(versusText);
}

void TeamsMenu::update(const float dt){

}

void TeamsMenu::handleEvent(sf::Event& event){
    switch(event.type){
        case sf::Event::Closed:
            app->window.close();
        break;

         case sf::Event::MouseButtonPressed: {

            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            if(backButton.clicked(x, y)){
                app->popState();
            }
            else if(playButton.clicked(x, y)){
                //app->pushState(new Playing(app, new MultiPlayerGame()));
            }
            break;
        }

        case sf::Event::MouseMoved: {
            int x = event.mouseMove.x;
            int y = event.mouseMove.y;

            backButton.hover(x, y);
            playButton.hover(x, y);

            break;
        }
    }
}
