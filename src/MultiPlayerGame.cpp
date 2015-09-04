#include "MultiPlayerGame.hpp"

MultiPlayerGame::MultiPlayerGame(std::vector<Player*> firstTeam,
                                 std::vector<Player*> secondTeam) : leftTeam(firstTeam),
                                                                    rightTeam(secondTeam){

    leftTeam.setPosition  (sf::Vector2f(SCREEN_LENGHT*0.30, SCREEN_HEIGHT*0.80));
    rightTeam.setPosition (sf::Vector2f(SCREEN_LENGHT*0.70, SCREEN_HEIGHT*0.80));

    leftTeam.focusMeter.setPosition (sf::Vector2f(LFOCUS_METER_POS_X, FOCUS_METER_POS_Y));
    rightTeam.focusMeter.setPosition(sf::Vector2f(RFOCUS_METER_POS_X, FOCUS_METER_POS_Y));

}

MultiPlayerGame::~MultiPlayerGame(){
    //dtor
}

void MultiPlayerGame::draw(const float dt){
    app->window.draw(forceMeter);
    app->window.draw(leftTeam);
    app->window.draw(rightTeam);
}

void MultiPlayerGame::update(const float dt){

    if(not gameover){
        leftTeam.update();
        rightTeam.update();

        int resultant = rightTeam.getTotalForce() - leftTeam.getTotalForce();

        sf::Vector2f force(resultant/(SCREEN_LENGHT*0.02), 0);

        forceMeter.setForce(resultant);

        leftTeam.applyForce(force);
        rightTeam.applyForce(force);

        testGameover();

    }
    else{
        std::cout << "Winner: " << winner << std::endl;
        app->popState();
    }
}

void MultiPlayerGame::handleEvent(sf::Event& event){
    switch(event.type){

        case sf::Event::Closed:
            app->window.close();
        break;

        case sf::Event::KeyPressed:
            char input = static_cast<char>(event.text.unicode);
            switch(input){

                case sf::Keyboard::Right:
                    if(rightTeam.getTotalForce() + 1 <= MAX_FORCE){
                        rightTeam.setForce(0, rightTeam.getPlayers().at(0)->getForce() + 1);
                    }
                break;

                case sf::Keyboard::Left:
                    if(rightTeam.getTotalForce() - 1 >= MIN_FORCE){
                        rightTeam.setForce(0, rightTeam.getPlayers().at(0)->getForce() - 1);
                    }
                break;

                case sf::Keyboard::A:
                    if(leftTeam.getTotalForce() + 1 <= MAX_FORCE){
                        leftTeam.setForce(0, leftTeam.getPlayers().at(0)->getForce() + 1);
                    }
                break;

                case sf::Keyboard::D:
                    if(leftTeam.getTotalForce() - 1 >= MIN_FORCE){
                        leftTeam.setForce(0, leftTeam.getPlayers().at(0)->getForce() - 1);
                    }
                break;
            }
        break;
    }
}

void MultiPlayerGame::testGameover(){
    if(leftTeam.getPosition().x > SCREEN_LENGHT/2){
        winner = 0;
        gameover = true;
    }

    if(rightTeam.getPosition().x < SCREEN_LENGHT/2){
        winner = 1;
        gameover = true;
    }
}
