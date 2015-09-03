#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include <game.hpp>
#include <player.hpp>
#include <PlayerGroup.hpp>
#include <artificialPlayer.hpp>

class MultiPlayerGame : public Game {
    public:
        MultiPlayerGame(std::vector<Player*> firstTeam, std::vector<Player*> secondTeam);
        virtual ~MultiPlayerGame();

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleEvent(sf::Event& event);

    private:
        int difficulty;
        int winner;
        PlayerGroup leftTeam;
        PlayerGroup rightTeam;

        virtual void testGameover();
};

#endif // MULTIPLAYERGAME_H
