#ifndef PLAYERGROUP_H
#define PLAYERGROUP_H

#include <player.hpp>
#include <focusMeter.hpp>
#include <SFML/Graphics.hpp>

class PlayerGroup : public sf::Drawable{
    public:
        PlayerGroup(std::vector<Player*> _players);
        virtual ~PlayerGroup();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        void addPlayer(Player* player);
        void update();
        void setForce(int playerID, int force);
        void setPosition(sf::Vector2f pos);
        void applyForce(sf::Vector2f _force);

        int getTotalForce();
        std::vector<Player*> getPlayers();
        sf::Vector2f getPosition();

        FocusMeter focusMeter;

    private:
        std::vector<Player*> players;

};

#endif // PLAYERGROUP_H
