//
// Created by keen on 19/04/2017.
//

#include "Display.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include <iomanip>

Display::Display() {

    mShape.setSize(sf::Vector2f{170.f, 30});
    mShape.setFillColor(sf::Color{50, 200, 100, 255});

    mFont.loadFromFile("Dong.ttf");
    mText.setFont(mFont);
    mText.setString(std::string{"0"});
    mText.setFillColor(sf::Color::White);
    mText.setCharacterSize(30);
    mText.setPosition(sf::Vector2f{130.f, 0.f});
}
void Display::addValue(std::string value, Type type) {
    int decimalLength{};
    if(type == Type::Number){
        std::string delim{"."};
        int pos = value.find(delim);
        //if something found
        if(pos != -1){
            decimalLength = value.length() - pos;
        }
    }
    mStrText.append(value);
    mText.setString(mStrText);
    mText.move(sf::Vector2f{-14.f  - (decimalLength *12.f), 0.f});
}

void Display::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mShape, states);
    target.draw(mText, states);
}


void Display::reset() {
    mStrText = "";
    mText.setString(mStrText);
    mText.setPosition(sf::Vector2f{100.f, 0.f});
}

