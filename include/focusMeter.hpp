#ifndef FOCUSMETER_H
#define FOCUSMETER_H

#include <player.hpp>
#include <iostream>

class FocusMeter : public sf::Drawable{
    public:
        FocusMeter(int posX, int posY, int sizeX, int sizeY);

        void addPlayer(Player* _player);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void update();

        sf::Vector2f getSize();

    private:
        std::vector<Player*> players;
        std::vector<sf::RectangleShape> meters; //trocar para sf::Sprite depois

        sf::Sprite background;
        sf::Sprite overlay;

        sf::RectangleShape m_body;
        sf::Vector2f m_size;

        sf::RectangleShape meterBody;
};

#endif // FOCUSMETER_H
