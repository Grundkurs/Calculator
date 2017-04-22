//
// Created by keen on 19/04/2017.
//

#ifndef CALCULATOR_APPLICATION_HPP
#define CALCULATOR_APPLICATION_HPP

#include "Calculator.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Application {
public:
    Application();
    void run();
private:
    void update();
    void render();

    sf::RenderWindow mWindow;
    Calculator mCalculator;
};


#endif //CALCULATOR_APPLICATION_HPP
