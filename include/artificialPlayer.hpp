#ifndef ARTIFICIALPLAYER_H
#define ARTIFICIALPLAYER_H

#include <player.hpp>


class ArtificialPlayer : public Player{
    public:
        ArtificialPlayer();
        virtual ~ArtificialPlayer();
        virtual void update();
        void setInitialForce(int _force);
    private:
        int initialForce;
        sf::Clock changeClock;


};

#endif // ARTIFICIALPLAYER_H
