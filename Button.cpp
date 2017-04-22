//
// Created by keen on 19/04/2017.
//

#include "Button.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Button::Button(Type type, std::string character)
: mShape(), mText(), mFont(), mValue(0), mType(type){
    if(type == Type::Number) mValue = std::stoi(character);

    mShape.setFillColor(sf::Color::Red);
    mShape.setSize(sf::Vector2f{40.f, 40.f});

    mFont.loadFromFile("Dong.ttf");
    mText.setFont(mFont);
    mText.setString(character);
    mText.setFillColor(sf::Color::White);
    mText.setCharacterSize(30);
    mText.setPosition(sf::Vector2f{5.f, 0.f});
}

void Button::select() {
    mShape.setFillColor(sf::Color{200, 100, 100,255});
}

void Button::deselect() {
    mShape.setFillColor(sf::Color{160, 100, 100,255});
}


int Button::getValue() const {
    return mValue;
}

Type Button::getType() const {
    return mType;
}


void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mShape, states);
    target.draw(mText, states);
}


sf::FloatRect Button::getRect() const {
    sf::FloatRect rect = mShape.getGlobalBounds();
    rect.top = getPosition().y;
    rect.left = getPosition().x;
    return rect;
}

