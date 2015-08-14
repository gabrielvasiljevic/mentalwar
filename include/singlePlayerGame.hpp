#ifndef SINGLEPLAYERGAME_H
#define SINGLEPLAYERGAME_H

#include <game.hpp>
#include <focusMeter.hpp>
#include <player.hpp>
#include <artificialPlayer.hpp>

class SinglePlayerGame : public Game{
    public:
        SinglePlayerGame(int difficulty);
        ~SinglePlayerGame();

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleEvent(sf::Event& event);

    protected:

    private:
        int difficulty;
        int winner;
        Player human;
        ArtificialPlayer machine;

        FocusMeter focusMeter;

        virtual void testGameover();

};

#endif // SINGLEPLAYERGAME_H
