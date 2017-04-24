//
// Created by keen on 19/04/2017.
//

#ifndef CALCULATOR_BUTTON_HPP
#define CALCULATOR_BUTTON_HPP


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>

enum class Type{Number, Plus, Minus, Multiply, Divide, Equal, AC, Comma};
class Button : public sf::Drawable, public sf::Transformable{
public:
    Button(Type type, std::string character);
    void select();
    void deselect();
    int getValue() const;
    Type getType() const;
    sf::FloatRect getRect() const;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::RectangleShape mShape;
    sf::Text mText;
    sf::Font mFont;
    float mValue;
    Type mType;

};


#endif //CALCULATOR_BUTTON_HPP
