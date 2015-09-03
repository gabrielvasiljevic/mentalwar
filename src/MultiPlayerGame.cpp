#include "MultiPlayerGame.hpp"

MultiPlayerGame::MultiPlayerGame(std::vector<Player*> firstTeam,
                                 std::vector<Player*> secondTeam) : leftTeam(firstTeam),
                                                                    rightTeam(secondTeam){

}

MultiPlayerGame::~MultiPlayerGame(){
    //dtor
}

void MultiPlayerGame::draw(const float dt){
    app->window.draw(forceMeter);
    app->window.draw(leftTeam);
    app->window.draw(rightTeam);
}

void MultiPlayerGame::update(const float dt){
    leftTeam.update();
    rightTeam.update();
}

void MultiPlayerGame::handleEvent(sf::Event& event){
    switch(event.type){
        case sf::Event::Closed:
            app->window.close();
        break;
        case sf::Event::KeyPressed:
            char input = static_cast<char>(event.text.unicode);
            switch(input){

                case sf::Keyboard::Right:

                break;

                case sf::Keyboard::Left:

                break;
            }
        break;
    }

}

void MultiPlayerGame::testGameover(){
    if(leftTeam.getPosition().x > SCREEN_LENGHT/2){
        winner = 0;
        gameover = true;
    }

    if(rightTeam.getPosition().x < SCREEN_LENGHT/2){
        winner = 1;
        gameover = true;
    }
}
