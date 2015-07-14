#include "application.hpp"

void Application::pushState(State* state){

    this->states.push(state);

    return;
}

void Application::popState(){

    delete this->states.top();
    this->states.pop();

    return;
}

void Application::changeState(State* state){
    if(!this->states.empty())
        popState();
    pushState(state);

    return;
}

State* Application::peekState() {
    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Application::mainLoop() {

    sf::Event event;

    sf::Clock clock;

    sf::Time elapsed;

    float dt;

    while(this->window.isOpen()){

        elapsed = clock.restart();
        dt = elapsed.asSeconds();

        if(peekState() == nullptr) continue;

        while(window.pollEvent(event)){

            //handleEvent(event);

            //if(confPanel.getActive()){
            //    confPanel.handleEvent(event);
            //}
            //else{
                peekState()->handleEvent(event);
            //}

        }

        peekState()->update(dt);

        this->window.clear(sf::Color::Black);

        peekState()->draw(dt);

        draw();

        this->window.display();

    }
}

void Application::draw(){
    /*if(globalWarningClock.getElapsedTime().asSeconds() < 4){
        window.draw(globalWarning);
    }
    if(confPanel.getActive()){
        window.draw(confPanel);
    }*/
}
/*
void Application::handleEvent(sf::Event& event){

    if(event.type == sf::Event::KeyPressed){
        switch(event.key.code){
            case sf::Keyboard::F2:
                confPanel.setActive( !confPanel.getActive() );
            break;

            case sf::Keyboard::F12:
                takeScreenshot();
            break;
        }
    }

}*/


void Application::takeScreenshot(){
    /*sf::Image screenshot = window.capture();

    std::string screenshotName = "MMC_ScreenShot_" + Utility::getDatestamp("") + "_" + Utility::getTimestamp("");

    screenshot.saveToFile("media/screenshots/" + screenshotName + ".png");

    globalWarning.setString(translation(L"Screenshot saved!"));
    globalWarningClock.restart();
    cout << "ScreenShot saved!" << endl;*/
}

Application::Application() {
/*
    globalWarning.setFont(fontsDAO.getFont("agencyBold"));
    globalWarning.setColor(sf::Color::Red);
    globalWarning.setCharacterSize(20U);
    globalWarning.setPosition(0, 0);
    globalWarning.setString("");

    Textures::loadTextures();

    sf::Image icon;

    icon.loadFromFile("media/images/icons/knightIcon.png");
*/
    window.create(sf::VideoMode(SCREEN_LENGHT, SCREEN_HEIGHT), GAME_TITLE, sf::Style::Close);
    //window.setIcon(256, 256, icon.getPixelsPtr());
    window.setFramerateLimit(FRAMERATE);

    //confPanel.setPosition((window.getSize().x/4*3)/4, (window.getSize().y/4*3)/4 - 96);

}

Application::~Application(){
    while(!this->states.empty()) popState();
}
