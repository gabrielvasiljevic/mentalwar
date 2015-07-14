#ifndef SOUNDSDAO_H
#define SOUNDSDAO_H

#include <iostream>
#include <map>
#include <fstream>
#include <SFML/Audio.hpp>

#ifndef soundsDAO
#define soundsDAO SoundsDAO::getInstance()
#endif


class SoundsDAO{
    public:
        static SoundsDAO& getInstance();
        sf::SoundBuffer& getSound(const std::string& soundName);

        void loadSounds();

    private:
        static SoundsDAO* instance;
        SoundsDAO(SoundsDAO const&);

        std::map<std::string, sf::SoundBuffer> sounds;

        void loadSound(const std::string& name, const std::string& filename);

        SoundsDAO(){};
};

#endif // SOUNDSDAO_H
