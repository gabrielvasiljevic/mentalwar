#ifndef FORCEMETER_H
#define FORCEMETER_H

#include <SFML/Graphics.hpp>


class ForceMeter : public sf::Drawable{
    public:
        ForceMeter(int posX, int posY, int sizeX, int sizeY);

        int getForce();
        void setForce(const int& force);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void update();

    private:
        int force = 0;
        sf::Sprite meter;
        sf::Sprite background;
        sf::Sprite overlay;

        sf::RectangleShape m_body;
        sf::Vector2f m_size;

        sf::RectangleShape meterBody;
};

#endif // FORCEMETER_H
