#pragma once 
#include "../../MainLibraries/main.hpp"
class Input {
public:
    bool isKeyPressedEvent(const std::optional<sf::Event >*event,const sf::Event::KeyPressed* keyboard, sf::Keyboard::Scancode key) const;
    bool isKeyPressed(sf::Keyboard::Key key) const;
    bool isButtonPressed(sf::Mouse::Button Button) const;
    bool isWheelPressedEventUp(
        const std::optional<sf::Event>* event,
        const sf::Event::MouseWheelScrolled* wheel
        , sf::Mouse::Wheel key) const;

    bool isWheelPressedEventDown(
        const std::optional<sf::Event>* event,
        const sf::Event::MouseWheelScrolled* wheel
        , sf::Mouse::Wheel key) const;

};
