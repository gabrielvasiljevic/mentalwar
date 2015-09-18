#include "singlePlayerGame.hpp"

SinglePlayerGame::SinglePlayerGame(int difficulty){
    human.setPosition   (sf::Vector2f(SCREEN_LENGHT*0.30, SCREEN_HEIGHT*0.80));
    machine.setPosition (sf::Vector2f(SCREEN_LENGHT*0.70, SCREEN_HEIGHT*0.80));
    machine.setInitialForce( 55 + 10*difficulty );

    focusMeter.setPosition(sf::Vector2f(LFOCUS_METER_POS_X, FOCUS_METER_POS_Y));

    focusMeter.addPlayer(&human);

    human.setForce(60 + 5*difficulty);

    human.setConnectionID(mindwaveModule.connect());

    if(human.getConnectionID() < 0){
        std::cout << "No connection" << std::endl;
    }
}

SinglePlayerGame::~SinglePlayerGame(){
    mindwaveModule.disconnect(human.getConnectionID());
}

void SinglePlayerGame::update(const float dt){

    if(not gameover){
        focusMeter.update();

        machine.update();
        if(updateClock.getElapsedTime().asSeconds() > 1){
            int att = mindwaveModule.getAttention(human.getConnectionID());
            if(att > 0){
               human.setForce(att);
            }

            updateClock.restart();
        }


        int resultant = machine.getForce() - human.getForce();

        sf::Vector2f force(resultant/(SCREEN_LENGHT*0.02), 0);

        forceMeter.setForce(resultant);

        human.applyForce(force);
        machine.applyForce(force);

        testGameover();

    }
    else{
        std::cout << "Winner: " << winner << std::endl;
        mindwaveModule.disconnect(human.getConnectionID());
        app->popState();
    }

}

void SinglePlayerGame::draw(const float dt){
    app->window.draw(forceMeter);
    app->window.draw(focusMeter);
    app->window.draw(human);
    app->window.draw(machine);
}

void SinglePlayerGame::handleEvent(sf::Event& event){
    switch(event.type){
        case sf::Event::Closed:
            app->window.close();
        break;
        case sf::Event::KeyPressed:
            char input = static_cast<char>(event.text.unicode);
            switch(input){

                case sf::Keyboard::Right:
                    if(human.getForce() - 1 >= MIN_FORCE){
                        human.setForce(human.getForce() - 1);
                    }
                break;

                case sf::Keyboard::Left:
                    if(human.getForce() + 1 <= MAX_FORCE){
                        human.setForce(human.getForce() + 1);
                    }
                break;
            }
        break;
    }

}

void SinglePlayerGame::testGameover(){
    if(human.getPosition().x > SCREEN_LENGHT/2){
        winner = 0;
        gameover = true;
    }

    if(machine.getPosition().x < SCREEN_LENGHT/2){
        winner = 1;
        gameover = true;
    }
}
