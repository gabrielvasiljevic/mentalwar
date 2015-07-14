#include "button.hpp"

Button::Button(){
    //ctor
}

Button::~Button(){
    //dtor
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(b_body);
    //target.draw(b_sprite);
    target.draw(b_text);

    return;
}

Button::Button(int x, int y, int size_x, int size_y, std::string desc, bool centerHorizontally, bool centerVertically){

    setPosition(x, y);
    setSize(size_x, size_y);

    b_text.setFont(fontsDAO.getFont("agency_bold"));

    selectedSound.setBuffer(soundsDAO.getSound("select"));

    clickedSound.setBuffer(soundsDAO.getSound("bip"));

    setText(desc);
    b_text.setCharacterSize(20U);
    b_text.setColor(sf::Color::Black);
    std::string filename = "";


    /*filename = "media/images/buttons/blank.png";


    b_texture = new sf::Texture();
    b_texture->loadFromFile(filename);
    b_sprite.setTexture(*b_texture);
*/
    update();
}

void Button::disable(){
    enabled = false;
    setColor(sf::Color(200, 200, 200, 150));
    return;
}

bool Button::contains(float x, float y){
    sf::FloatRect body(getPosition().x, getPosition().y, b_size.x, b_size.y);
    if(body.contains(x, y)){
        return true;
    }
    else{
        return false;
    }
}

bool Button::clicked(float x, float y){
    if(contains(x, y) and sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(enabled)
            clickedSound.play();
        return true;
    }
    else{
        return false;
    }
}

void Button::hover(const float& x, const float& y){
    if(enabled and changeOnHover){
        if(contains(x, y)){
            if(not hovered){
                setColor(sf::Color::Green);
                selectedSound.play();
                hovered = true;
            }
        }
        else{
            setColor(sf::Color::White);
            hovered = false;
        }
    }
}

void Button::disableHover(){
    changeOnHover = false;
    return;
}

void Button::changeIcon(const std::string& imagename){
    delete b_texture;
    b_texture = new sf::Texture();
    b_texture->loadFromFile("media/images/" + imagename);
    b_sprite.setTexture(*b_texture);
}

void Button::changeTextSize(const unsigned int size){
    b_text.setCharacterSize(size);
    update();
    /*sf::FloatRect textRect = text.getLocalBounds();

    ;
    text.setPosition(pos_x + square.getLocalBounds().width/2,
                     pos_y + square.getLocalBounds().height/2);*/
}

void Button::setSizeToText(){
    sf::Vector2f newSize(b_text.getLocalBounds().width, b_text.getLocalBounds().height);
    b_size = newSize;
    b_body.setSize(b_size);
}

void Button::setSize(float x, float y){
    sf::Vector2f newSize(x, y);
    b_size = newSize;
    b_body.setSize(b_size);
    update();
}

void Button::setPosition(float x, float y){
    sf::Vector2f newPosition(x, y);
    b_position = newPosition;
    b_body.setPosition(b_position);
    b_sprite.setPosition(x, y);
    b_text.setPosition(x, y);
    update();
}

void Button::setText(const std::string& text){
    b_string = text;
    b_text.setString(b_string);
    update();
}

void Button::setFont(const sf::Font& font){
    b_font = font;
    b_text.setFont(b_font);
    update();
}

void Button::setColor(const sf::Color& color){
    b_color = color;
    b_body.setFillColor(color);
}

sf::Vector2f Button::getPosition(){
    return b_position;
}

void Button::update() {
    if (b_size.x > 0 && b_size.y > 0 && b_text.getString() != "") {
        b_text.setOrigin(b_text.getLocalBounds().left + b_text.getLocalBounds().width/2, b_text.getLocalBounds().top + b_text.getLocalBounds().height/2);
        b_text.setPosition(b_position.x + b_body.getLocalBounds().width/2, b_position.y + b_body.getLocalBounds().height/2);
    }
}
