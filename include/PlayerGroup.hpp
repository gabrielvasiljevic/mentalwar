#ifndef PLAYERGROUP_H
#define PLAYERGROUP_H

#include <player.hpp>
#include <focusMeter.hpp>
#include <SFML/Graphics.hpp>

class PlayerGroup : public sf::Drawable{
    public:
        PlayerGroup();
        virtual ~PlayerGroup();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        void addPlayer(Player* player);
        void update(const float dt);
        void setForce(int playerID, int force);

        int getTotalForce();
        std::vector<Player*> getPlayers();
        sf::Vector2f getPosition();

    protected:
    private:
        std::vector<Player*> players;
        FocusMeter focusMeter;
};

#endif // PLAYERGROUP_H
