#ifndef TEAMHOLDER_H
#define TEAMHOLDER_H

#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <button.hpp>

class TeamHolder : public sf::Drawable{
    public:
        TeamHolder();
        virtual ~TeamHolder();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void handleEvent(sf::Event& event);

        void addPlayer(Player* player);

    private:
        std::vector<Player*> players;

        Button addPlayerButton;

        sf::RectangleShape _body;
        sf::Vector2f _size;

};

#endif // TEAMHOLDER_H
