#include "input.hpp"

bool Input::isKeyPressed(sf::Keyboard::Key key) const {
	if (sf::Keyboard::isKeyPressed(key)) {
		return true;
	}
	return false;
}

bool Input::isKeyPressedEvent(const std::optional<sf::Event>* event, const sf::Event::KeyPressed* keyboard, sf::Keyboard::Scancode key) const {
	if (event->has_value()) {
			if (keyboard->scancode== key) {
				return true;
			}

	}
	return false;
}
	