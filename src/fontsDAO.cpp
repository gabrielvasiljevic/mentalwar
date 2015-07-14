#include "fontsDAO.h"


FontsDAO& FontsDAO::getInstance(){
    static FontsDAO instance;
    return instance;
}

void FontsDAO::loadFonts(){

    loadFont("agency_bold",     "agency_bold.ttf");
    loadFont("anilin_bold",     "anilin_bold.ttf");
    loadFont("anilin_regular",  "anilin_regular.ttf");
    loadFont("carbon",          "carbon.ttf");
    loadFont("circhand",        "circhand.ttf");


    return;
}

void FontsDAO::loadFont(const std::string& name, const std::string& filename){
    sf::Font font;
    font.loadFromFile("media/fonts/" + filename);

    this->fonts[name] = font;

    return;
}

sf::Font& FontsDAO::getFont(const std::string& font){
    try{
        return this->fonts.at(font);
    }
    catch(std::out_of_range& e){
        std::cout << "Font " << font << " not found." << std::endl;
        return fonts.at("agency_bold");
    }
}
