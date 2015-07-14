#ifndef FONTSDAO_H
#define FONTSDAO_H

#include <iostream>
#include <map>
#include <fstream>
#include <SFML/Graphics.hpp>

#ifndef fontsDAO
#define fontsDAO FontsDAO::getInstance()
#endif

class FontsDAO{
    public:
        static FontsDAO& getInstance();
        sf::Font& getFont(const std::string& fontName);

        void loadFonts();

    private:
        static FontsDAO* instance;
        FontsDAO(FontsDAO const&);

        std::map<std::string, sf::Font> fonts;

        void loadFont(const std::string& name, const std::string& filename);

        FontsDAO(){};
};

#endif // FONTSDAO_H
