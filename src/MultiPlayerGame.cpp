#include "MultiPlayerGame.hpp"

MultiPlayerGame::MultiPlayerGame(){
    //ctor
}

MultiPlayerGame::MultiPlayerGame(int difficulty){
    //ctor
}

MultiPlayerGame::~MultiPlayerGame(){
    //dtor
}

void MultiPlayerGame::draw(const float dt){

}

void MultiPlayerGame::update(const float dt){

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
    if(leftTeam.at(0)->getPosition().x > SCREEN_LENGHT/2){
        winner = 0;
        gameover = true;
    }

    if(rightTeam.at(0)->getPosition().x < SCREEN_LENGHT/2){
        winner = 1;
        gameover = true;
    }
}
