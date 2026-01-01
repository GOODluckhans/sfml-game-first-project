#include "input.hpp"

bool Input::isKeyPressed(sf::Keyboard::Key key) const {
	if (sf::Keyboard::isKeyPressed(key)) {
		return true;
	}
	return false;
}

bool Input::isButtonPressed(sf::Mouse::Button Button) const {
	if (sf::Mouse::isButtonPressed(Button)) {
		return true;
	}
	return false;
}


bool Input::isWheelPressedEventUp(
	const std::optional<sf::Event>* event,
	const sf::Event::MouseWheelScrolled* wheel
	, sf::Mouse::Wheel key) const {
	return wheel->wheel == key && wheel->delta > 0.f;
}
bool Input::isWheelPressedEventDown(
	const std::optional<sf::Event>* event,
	const sf::Event::MouseWheelScrolled* wheel
	, sf::Mouse::Wheel key) const {
	return wheel->wheel == key && wheel->delta < 0.f;

}



bool Input::isKeyPressedEvent(const std::optional<sf::Event>* event, const sf::Event::KeyPressed* keyboard, sf::Keyboard::Scancode key) const {
	if (event->has_value()) {
			if (keyboard->scancode== key) {
				return true;
			}

	}
	return false;
}
	