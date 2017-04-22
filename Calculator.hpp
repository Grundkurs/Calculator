//
// Created by keen on 19/04/2017.
//

#ifndef CALCULATOR_CALCULATOR_HPP
#define CALCULATOR_CALCULATOR_HPP

#include "Button.hpp"
#include "Display.hpp"
#include "Compute.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Calculator : public sf::Drawable{
public:
    Calculator(sf::RenderWindow* window);
    void update();
    void handleEvents(const sf::Event& event);

    void pushLHS();
    void pushOperand();
    void pushResult();
    void setOperator(Type type);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


    sf::RectangleShape mCaseRect;
    std::vector<std::unique_ptr<Button>> mButtons;
    Display mDisplay;
    sf::RenderWindow* mWindow;
    Button* mSelectedButton;
    Compute mComputer;
    Type mOperator;
};


#endif //CALCULATOR_CALCULATOR_HPP
