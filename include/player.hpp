#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable{
    public:
        Player();
        virtual ~Player();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        int getForce();
        void setForce(int force);
        void applyForce(sf::Vector2f _force);

        std::string getName();
        void setName(std::string name);

        void setPosition(sf::Vector2f newPos);
        sf::Vector2f getPosition();

    protected:
        std::string name;
        int force;



        sf::Sprite sprite;
        sf::RectangleShape p_body;
        sf::Vector2f p_position;
};

#endif // PLAYER_H
