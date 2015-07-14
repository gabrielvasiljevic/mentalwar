#include "focusMeter.hpp"

FocusMeter::FocusMeter(int posX, int posY, int sizeX, int sizeY) {
    sf::Vector2f newSize(sizeX, sizeY);
    m_size = newSize;
    m_body.setSize(m_size);
    m_body.setPosition(posX, posY);
    m_body.setFillColor(sf::Color::White);

}

void FocusMeter::addPlayer(Player* _player) {
    players.push_back(_player);
    sf::RectangleShape newMeter(sf::Vector2f(getSize().x, getSize().y*0.05));
    newMeter.setFillColor(sf::Color::Blue);
    newMeter.setPosition(m_body.getGlobalBounds().left, m_body.getGlobalBounds().top + getSize().y);
    meters.push_back(newMeter);
}

void FocusMeter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //target.draw(background);
    //target.draw(meter);
    //target.draw(overlay);

    target.draw(m_body);
    for(auto meter : meters){
        target.draw(meter);
    }

}

void FocusMeter::update() {

    float bottom = m_body.getGlobalBounds().top + m_body.getSize().y;

    for(int i = 0; i < players.size(); i++){

        float newPos = bottom - (m_body.getSize().y*players[i]->getForce())/100.0f;

        meters[i].setPosition(meters[i].getPosition().x, newPos); //Keep the X position, changes only height
    }
}

sf::Vector2f FocusMeter::getSize(){
    return m_body.getSize();
}
