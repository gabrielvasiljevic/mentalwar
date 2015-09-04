#include "PlayerHolder.hpp"

PlayerHolder::PlayerHolder(std::string name, int posX, int posY){

    body.setSize(sf::Vector2f(0.32*SCREEN_LENGHT, 0.12*SCREEN_HEIGHT));
    body.setFillColor(sf::Color::Black);
    body.setOutlineColor(sf::Color::White);
    body.setOutlineThickness(-1);

    playerName.setFont(fontsDAO.getFont("agency_bold"));
    playerName.setCharacterSize(16U);
    playerName.setColor(sf::Color::White);
    playerName.setString(name);

    setPosition(posX, posY);

    removeButton.setSize(32, 32);
    removeButton.setColor(sf::Color::Red);
    removeButton.setText("-");

    player = new Player();
}

PlayerHolder::~PlayerHolder(){
    //dtor
}

void PlayerHolder::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(body);
    target.draw(playerName);
    target.draw(removeButton);
}

void PlayerHolder::handleEvent(sf::Event& event){

}

void PlayerHolder::setPosition(int x, int y){
    body.setPosition(sf::Vector2f(x, y));
    playerName.setPosition(sf::Vector2f(x + 4, y + 8));
    removeButton.setPosition(x + body.getSize().x - 32 - 8, y + body.getSize().y*0.5 - 16);
}

sf::Vector2f PlayerHolder::getPosition(){
    return body.getPosition();
}


Player* PlayerHolder::getPlayer(){
    return player;
}
