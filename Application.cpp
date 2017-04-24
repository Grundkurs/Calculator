//
// Created by keen on 19/04/2017.
//

#include "Application.hpp"
#include <SFML/Window/Event.hpp>
Application::Application()
: mWindow(sf::VideoMode{260,350}, "Ellens Calculator"), mCalculator(&mWindow){

}


void Application::run() {
    while(mWindow.isOpen()){

        sf::Event event;
        while(mWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed) mWindow.close();

            mCalculator.handleEvents(event);
        }
        update();
        render();
    }
}

void Application::update() {
    mCalculator.update();
}

void Application::render() {
    mWindow.clear(sf::Color::Blue);
    mWindow.draw(mCalculator);
    mWindow.display();
}

