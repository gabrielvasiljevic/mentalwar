#include "TeamsMenu.hpp"

TeamsMenu::TeamsMenu(Application* app) : backButton(250, 500, 96, 32, "Back"),
                                         playButton(450, 500, 96, 32, "Play!"),
                                         leftTeam (0.1*SCREEN_LENGHT,  0.2*SCREEN_HEIGHT, 0.35*SCREEN_LENGHT, 0.5*SCREEN_HEIGHT, "Team 1"),
                                         rightTeam(0.55*SCREEN_LENGHT, 0.2*SCREEN_HEIGHT, 0.35*SCREEN_LENGHT, 0.5*SCREEN_HEIGHT, "Team 2"){
    this->app = app;

    versusText.setFont(fontsDAO.getFont("agency_bold"));
    versusText.setCharacterSize(24U);
    versusText.setColor(sf::Color::White);
    versusText.setString("VS");
    versusText.setPosition(0.5*SCREEN_LENGHT - 8, 0.5*SCREEN_HEIGHT - versusText.getLocalBounds().height - 16);

}

TeamsMenu::~TeamsMenu(){
    //dtor
}

void TeamsMenu::draw(const float dt){
    app->window.draw(backButton);
    app->window.draw(playButton);
    app->window.draw(versusText);

    app->window.draw(leftTeam);
    app->window.draw(rightTeam);
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
                if(leftTeam.getPlayers().size() > 0 and rightTeam.getPlayers().size() > 0){
                    app->pushState(new Playing(app, new MultiPlayerGame(leftTeam.getPlayers(), rightTeam.getPlayers())));
                }
            }

            leftTeam.handleEvent(event);
            rightTeam.handleEvent(event);
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
