#ifndef PLAYERHOLDER_H
#define PLAYERHOLDER_H

#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <button.hpp>
#include <global.hpp>

class PlayerHolder : public sf::Drawable{
    public:
        PlayerHolder(std::string name, int posX, int posY);
        virtual ~PlayerHolder();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void handleEvent(sf::Event& event);

        void setPosition(int x, int y);
        sf::Vector2f getPosition();
        Player* getPlayer();

        Button removeButton;

    protected:
    private:
        Player* player;
        int slotID;

        sf::Text playerName;
        sf::RectangleShape body;
};

#endif // PLAYERHOLDER_H
