#ifndef TEAMSMENU_HPP
#define TEAMSMENU_HPP

#include <state.hpp>
#include <playing.hpp>
#include <button.hpp>
#include <MultiPlayerGame.hpp>

class TeamsMenu : public State{
    public:
        TeamsMenu(Application* app);
        virtual ~TeamsMenu();

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleEvent(sf::Event& event);
    protected:
    private:

        Button backButton;
        Button playButton;

        sf::Text versusText;
};

#endif // TEAMSMENU_HPP
