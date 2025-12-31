#pragma once 
#include "../../MainLibraries/main.hpp"
class Input {
public:
    bool isKeyPressedEvent(const std::optional<sf::Event >*event,const sf::Event::KeyPressed* keyboard, sf::Keyboard::Scancode key) const;
    bool isKeyPressed(sf::Keyboard::Key key) const;
};
