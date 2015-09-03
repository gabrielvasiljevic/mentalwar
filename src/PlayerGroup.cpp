#include "PlayerGroup.hpp"

PlayerGroup::PlayerGroup(std::vector<Player*> _players){
    for(auto& player : _players){
        addPlayer(player);
        focusMeter.addPlayer(player);
    }
}

PlayerGroup::~PlayerGroup(){
    //dtor
}

void PlayerGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(auto& player: players){
        player->draw(target, states);
    }

    target.draw(focusMeter);
}

void PlayerGroup::addPlayer(Player* player){
    players.push_back(player);
}

void PlayerGroup::update(){
    for(auto& player: players){
        player->update();
    }
}

void PlayerGroup::setForce(int playerID, int force){
    players.at(playerID)->setForce(force);
}

int PlayerGroup::getTotalForce(){
    int total = 0;

    for(auto& player : players){
        total += player->getForce();
    }

    total /= players.size();

    return total;
}

std::vector<Player*> PlayerGroup::getPlayers(){
    return players;
}


sf::Vector2f PlayerGroup::getPosition(){
    return players.at(0)->getPosition();
}
