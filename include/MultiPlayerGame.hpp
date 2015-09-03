#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include <game.hpp>
#include <player.hpp>
#include <PlayerGroup.hpp>
#include <artificialPlayer.hpp>

class MultiPlayerGame : public Game {
    public:
        MultiPlayerGame();
        MultiPlayerGame(int difficulty);
        virtual ~MultiPlayerGame();

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleEvent(sf::Event& event);
    protected:

    private:
        int difficulty;
        int winner;
        std::vector<Player*> leftTeam;
        std::vector<Player*> rightTeam;

        virtual void testGameover();
};

#endif // MULTIPLAYERGAME_H
