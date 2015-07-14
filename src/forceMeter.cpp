#include "forceMeter.hpp"

#include <iostream>

ForceMeter::ForceMeter(int posX, int posY, int sizeX, int sizeY){
    sf::Vector2f newSize(sizeX, sizeY);
    m_size = newSize;
    m_body.setSize(m_size);
    m_body.setPosition(posX, posY);
    m_body.setFillColor(sf::Color::White);

    meterBody.setPosition(posX + sizeX/2, posY);
    meterBody.setSize(sf::Vector2f(sizeX/100.0, sizeY));
    meterBody.setFillColor(sf::Color::Blue);

    setForce(0);
    update();

}

int ForceMeter::getForce(){
    return force;
}

void ForceMeter::setForce(const int& force){
    this->force = force;
    update();
}


void ForceMeter::update(){
    float middle = m_body.getGlobalBounds().left + (m_body.getSize().x)/2;

    float newPosition = middle + ( force * (m_body.getSize().x/2) ) / 100; //normalized

    meter.setPosition(newPosition, m_body.getPosition().y);
    meterBody.setPosition(meter.getPosition());
}

void ForceMeter::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    //target.draw(background);
    //target.draw(meter);
    //target.draw(overlay);

    target.draw(m_body);
    target.draw(meterBody);
}
