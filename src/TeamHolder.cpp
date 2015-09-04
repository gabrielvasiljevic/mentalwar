#include "TeamHolder.hpp"

TeamHolder::TeamHolder(int posX, int posY, int sizeX, int sizeY, std::string _title){
    _body.setFillColor(sf::Color::Black);
    _body.setOutlineColor(sf::Color::White);
    _body.setOutlineThickness(-2);

    setSize(sizeX, sizeY);
    setPosition(posX, posY);

    title.setFont(fontsDAO.getFont("agency_bold"));
    title.setCharacterSize(20U);
    title.setColor(sf::Color::White);
    title.setString(_title);
    title.setPosition(posX + 8, posY - 24);

    addPlayerButton.setColor(sf::Color::Green);
    addPlayerButton.setText("+");
    addPlayerButton.setSize(32, 32);
    addPlayerButton.setPosition(posX + _body.getGlobalBounds().width*0.5 - 16, posY + _body.getGlobalBounds().height*0.95 + 24);
}

TeamHolder::~TeamHolder(){
    //dtor
}

void TeamHolder::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_body);
    target.draw(title);
    for(auto& player : players){
        target.draw(*player);
    }
    target.draw(addPlayerButton);
}

void TeamHolder::handleEvent(sf::Event& event){

    switch(event.type){

         case sf::Event::MouseButtonPressed: {

            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            if(addPlayerButton.clicked(x, y)){
                if(players.size() < maxPlayers){
                    PlayerHolder* player = new PlayerHolder("Player", _body.getPosition().x + 12, _body.getPosition().y + 4 + 73*players.size());
                    addPlayer(player);
                }
            }

            for(int i = 0; i < players.size(); i++){
                if(players.at(i)->removeButton.clicked(x, y)){
                    removePlayer(i);
                }
            }

            break;
        }
    }
}

void TeamHolder::addPlayer(PlayerHolder* player){
    players.push_back(player);
}

void TeamHolder::removePlayer(int slotID){

    int n = players.size(); //number of players

    if(slotID < n - 1){ //If there are players after the one we are deleting...
        for(int i = slotID + 1; i < n; i++){
            sf::Vector2f pos = players.at(i)->getPosition();
            players.at(i)->setPosition(pos.x, pos.y - 73); //Set his position higher
        }
    }

    players.erase(players.begin() + slotID); //Erase the player

}

void TeamHolder::setSize(float x, float y){
    _size = sf::Vector2f(x, y);
    _body.setSize(_size);
}

void TeamHolder::setPosition(float x, float y){
    _body.setPosition(x, y);
}

std::vector<Player*> TeamHolder::getPlayers(){
    std::vector<Player*> result;

    for(auto& player : players){
        result.push_back(player->getPlayer());
    }

    return result;
}

