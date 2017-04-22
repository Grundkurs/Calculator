//
// Created by keen on 19/04/2017.
//

#ifndef CALCULATOR_DISPLAY_HPP
#define CALCULATOR_DISPLAY_HPP

#include "Button.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>

class Display : public sf::Drawable, public sf::Transformable {
public:
    Display();

    void addValue(std::string value, Type type = Type::Number);
    void reset();


private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::RectangleShape mShape;
    std::string mStrText;
    sf::Text mText;
    sf::Font mFont;
};


#endif //CALCULATOR_DISPLAY_HPP
