#include <iostream>

#include "application.hpp"
#include "mainMenu.hpp"

using namespace std;

int main(){

    fontsDAO.loadFonts();

    soundsDAO.loadSounds();

    Application app;

    app.pushState(new MainMenu(&app));

    app.mainLoop();

    return 0;
}
