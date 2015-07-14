#include "game.hpp"

Game::Game() : forceMeter(200, 50, SCREEN_LENGHT*0.5, SCREEN_HEIGHT*0.12){

}

Game::~Game(){
    //dtor
}

void Game::draw(const float dt){
    app->window.draw(background);
    app->window.draw(forceMeter);
}

void Game::update(const float dt){

}

void Game::handleEvent(sf::Event& event){
    switch(event.type){
        case sf::Event::Closed:
            app->window.close();
        break;
    }

}

void Game::setApp(Application* app){
    this->app = app;
}

void Game::testGameover(){

}
