#ifndef TEAMHOLDER_H
#define TEAMHOLDER_H

#include <SFML/Graphics.hpp>
#include <PlayerHolder.hpp>
#include <player.hpp>
#include <button.hpp>
#include <global.hpp>

class TeamHolder : public sf::Drawable{
    public:
        TeamHolder(int posX, int posY, int sizeX, int sizeY, std::string _title);
        virtual ~TeamHolder();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void handleEvent(sf::Event& event);

        void addPlayer(PlayerHolder* player);
        void removePlayer(int slotID);

        void setSize        (float x, float y);
        void setPosition    (float x, float y);

        std::vector<Player*> getPlayers();

    private:
        std::vector<PlayerHolder*> players;

        Button addPlayerButton;

        sf::Text title;
        sf::RectangleShape _body;
        sf::Vector2f _size;
        const int maxPlayers = 4;

};

#endif // TEAMHOLDER_H
