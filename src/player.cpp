#include "player.hpp"

Player::Player(){
    force = 60;
    name = "P";
    p_body.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE*2));
}

Player::~Player(){
    //dtor
}

int Player::getForce(){
    return force;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(p_body);
    //target.draw(sprite);
}


void Player::setForce(int force){
    if(force <= MAX_FORCE and force >= MIN_FORCE){
        this->force = force;
    }
}

std::string Player::getName(){
    return name;
}

void Player::setName(std::string name){
    this->name = name;
}

void Player::update(){

}


void Player::setPosition(sf::Vector2f newPos){
    sprite.setOrigin(p_body.getLocalBounds().width/2, p_body.getLocalBounds().height/2);
    p_body.setOrigin(p_body.getLocalBounds().width/2, p_body.getLocalBounds().height/2);

    this->p_position = newPos;
    this->p_body.setPosition(newPos);
    this->sprite.setPosition(newPos);
}

sf::Vector2f Player::getPosition(){
    return p_position;
}

void Player::applyForce(sf::Vector2f _force){
    setPosition(getPosition() + _force);
}

