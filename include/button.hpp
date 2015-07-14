#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include "fontsDAO.hpp"
#include "soundsDAO.hpp"

class Button : public sf::Drawable{
    public:
        Button();
        Button(int x, int y, int size_x, int size_y, std::string desc, bool centerHorizontally = false, bool centerVertically = false);
        virtual ~Button();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool clicked    (float x, float y);
        bool contains   (float x, float y);
        bool isEnabled  ();
        void action     ();

        virtual void hover(const float& x, const float& y);

        void disable        ();
        void disableHover   ();
        void setSizeToText  ();
        void setSize        (float x, float y);
        void setPosition    (float x, float y);
        void setText        (const std::string& text);
        void setFont        (const sf::Font& font);
        void setColor       (const sf::Color& color);

        sf::Vector2f getPosition();

        void changeIcon     (const std::string& imagename);
        void changeTextSize (const unsigned int size);
        void update         ();


    protected:
        bool enabled = true;
        bool hovered = false;
        bool changeOnHover = true;
        sf::Color hoverColor = sf::Color::Green;
    private:
        sf::RectangleShape b_body;
        sf::Vector2f b_size;
        sf::Vector2f b_position;

        sf::Texture* b_texture;
        sf::Sprite b_sprite;

        std::string b_string;
        sf::Text b_text;
        sf::Font b_font;

        sf::Color b_color;

        sf::Sound selectedSound;
        sf::Sound clickedSound;
};

#endif // BUTTON_H
