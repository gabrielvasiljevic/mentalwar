#include "soundsDAO.h"


SoundsDAO& SoundsDAO::getInstance(){
    static SoundsDAO instance;
    return instance;
}

void SoundsDAO::loadSounds(){

    loadSound("bip",      "bip.wav");
    loadSound("select",   "select.wav");
    loadSound("deselect", "deselect.wav");

    return;
}

void SoundsDAO::loadSound(const std::string& name, const std::string& filename){

    sf::SoundBuffer buffer;
    buffer.loadFromFile("media/sounds/" + filename);

    this->sounds[name] = buffer;

    return;
}

sf::SoundBuffer& SoundsDAO::getSound(const std::string& sound){
    try{
        return this->sounds.at(sound);
    }
    catch(std::out_of_range& e){
        std::cout << "Sound " << sound << " not found." << std::endl;
        return sounds.at("bip");
    }
}
