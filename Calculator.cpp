//
// Created by keen on 19/04/2017.
//

#include "Calculator.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>

Calculator::Calculator(sf::RenderWindow* window)
: mWindow(window){


    mDisplay.setPosition(sf::Vector2f{0.f, 40.f});

    mCaseRect.setSize(sf::Vector2f{260.f, 350.f});
    mCaseRect.setFillColor(sf::Color{80,80,50,255});

    std::unique_ptr<Button> button_1 = std::make_unique<Button>(Type::Number, "1");
    button_1->setPosition(sf::Vector2f{20.f, 100.f});
    mButtons.push_back(std::move(button_1));

    std::unique_ptr<Button> button_2 = std::make_unique<Button>(Type::Number,"2");
    button_2->setPosition(sf::Vector2f{65.f, 100.f});
    mButtons.push_back(std::move(button_2));

    std::unique_ptr<Button> button_3 = std::make_unique<Button>(Type::Number,"3");
    button_3->setPosition(sf::Vector2f{110.f, 100.f});
    mButtons.push_back(std::move(button_3));

    std::unique_ptr<Button> button_4 = std::make_unique<Button>(Type::Number,"4");
    button_4->setPosition(sf::Vector2f{20.f, 145.f});
    mButtons.push_back(std::move(button_4));

    std::unique_ptr<Button> button_5 = std::make_unique<Button>(Type::Number,"5");
    button_5->setPosition(sf::Vector2f{65.f, 145.f});
    mButtons.push_back(std::move(button_5));

    std::unique_ptr<Button> button_6 = std::make_unique<Button>(Type::Number,"6");
    button_6->setPosition(sf::Vector2f{110.f, 145.f});
    mButtons.push_back(std::move(button_6));

    std::unique_ptr<Button> button_7 = std::make_unique<Button>(Type::Number,"7");
    button_7->setPosition(sf::Vector2f{20.f, 190.f});
    mButtons.push_back(std::move(button_7));

    std::unique_ptr<Button> button_8 = std::make_unique<Button>(Type::Number,"8");
    button_8->setPosition(sf::Vector2f{65.f, 190.f});
    mButtons.push_back(std::move(button_8));

    std::unique_ptr<Button> button_9 = std::make_unique<Button>(Type::Number,"9");
    button_9->setPosition(sf::Vector2f{110.f, 190.f});
    mButtons.push_back(std::move(button_9));

    std::unique_ptr<Button> button_0 = std::make_unique<Button>(Type::Number,"0");
    button_0->setPosition(sf::Vector2f{65.f, 235.f});
    mButtons.push_back(std::move(button_0));

    std::unique_ptr<Button> button_Plus = std::make_unique<Button>(Type::Plus, "+");
    button_Plus->setPosition(sf::Vector2f{155.f, 100.f});
    mButtons.push_back(std::move(button_Plus));

    std::unique_ptr<Button> button_Minus = std::make_unique<Button>(Type::Minus, "-");
    button_Minus ->setPosition(sf::Vector2f{155.f, 145.f});
    mButtons.push_back(std::move(button_Minus ));

    std::unique_ptr<Button> button_Multiplicate = std::make_unique<Button>(Type::Multiply, "*");
    button_Multiplicate ->setPosition(sf::Vector2f{155.f, 190.f});
    mButtons.push_back(std::move(button_Multiplicate ));

    std::unique_ptr<Button> button_Divide = std::make_unique<Button>(Type::Divide, ":");
    button_Divide->setPosition(sf::Vector2f{155.f, 235.f});
    mButtons.push_back(std::move(button_Divide));

    std::unique_ptr<Button> button_Equal = std::make_unique<Button>(Type::Equal, "=");
    button_Equal->setPosition(sf::Vector2f{155.f, 280.f});
    mButtons.push_back(std::move(button_Equal));

    std::unique_ptr<Button> button_AC = std::make_unique<Button>(Type::AC, "AC");
    button_AC->setPosition(sf::Vector2f{200.f, 100.f});
    mButtons.push_back(std::move(button_AC));

    std::unique_ptr<Button> button_comma = std::make_unique<Button>(Type::Comma, ".");
    button_comma->setPosition(sf::Vector2f{110.f, 235.f});
    mButtons.push_back(std::move(button_comma));
}

void Calculator::update() {

    mSelectedButton = nullptr;
    for(auto& i : mButtons){
        sf::Vector2i mousePos = sf::Mouse::getPosition(*mWindow);
        if(i->getRect().contains(sf::Vector2f{mousePos.x, mousePos.y})){
            i->select();
            mSelectedButton = i.get();

        }
        else{
            i->deselect();
        }

    }
}


void Calculator::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mCaseRect);
    for(auto& i : mButtons){
        target.draw(*i);
    }
    target.draw(mDisplay);
}

void Calculator::handleEvents(const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (mSelectedButton) {
            Type type = mSelectedButton->getType();
            switch (type) {
                case (Type::Number): {
                    int num = mSelectedButton->getValue();
                    mComputer.addDigit(num);
                    mDisplay.addValue(std::to_string(num));
                    break;
                }
                case (Type::Minus): {

                    if(mComputer.getState() == State::LHS && mComputer.lhsEmpty()){
                        mComputer.addDigit(0);
                        mDisplay.addValue(std::to_string(0));
                        mComputer.setOperator(type);
                        mComputer.setState(State::RHS);
                    }
                    else{
                        mComputer.setState(State::RHS);
                        mComputer.compute();
                        mComputer.setOperator(type);

                    }
                    mDisplay.addValue("-", Type::Minus);
                    break;
                }
                case (Type::Plus): {
                    if(mComputer.getState() == State::LHS && mComputer.lhsEmpty()){
                        mDisplay.addValue("+", Type::Plus);
                    }
                    else {
                        mComputer.compute();

                        mDisplay.addValue("+", Type::Plus);
                        mComputer.setOperator(type);
                        mComputer.setState(State::RHS);
                    }
                    break;
                    }

                case (Type::Multiply): {
                    mComputer.setState(State::RHS);
                    mComputer.compute();
                    mComputer.setOperator(type);
                    mDisplay.addValue("*", Type::Multiply);

                    break;
                }

                case (Type::Divide): {
                    mComputer.setState(State::RHS);
                    mComputer.compute();
                    mComputer.setOperator(type);
                    mDisplay.addValue("/", Type::Multiply);
                    break;
                }
                case (Type::Equal): {

                    mComputer.compute();
                    mDisplay.reset();
                    std::string result = std::to_string(mComputer.getResult());
                    if(result.size() > 1 && result[0] == '0') result.erase(0, 1);
                    mDisplay.addValue(result);
                    break;
                }
                case (Type::AC): {
                    mComputer.reset();
                    mDisplay.reset();
                    break;
                }

                case (Type::Comma): {
                    mComputer.setComma();
                    mDisplay.addValue(",", Type::Comma);
                    break;
                }
            }
        }
    }
}