#include "playing.hpp"


Playing::Playing(Application* app, Game* game){
    this->app = app;
    this->game = game;
    game->setApp(app);

}


void Playing::draw(const float dt){
    game->draw(dt);
}

void Playing::handleEvent(sf::Event& event){
    game->handleEvent(event);
}

void Playing::update(const float dt){
    game->update(dt);
}
