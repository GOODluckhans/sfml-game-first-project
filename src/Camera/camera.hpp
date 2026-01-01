#pragma once 
#include "../../MainLibraries/main.hpp"
#include "../../src/input/input.hpp"
class Camera {
private:
	sf::View view;
	float followSpeed = 5.f;
	sf::RenderWindow& window;  // reference
	float cameraZoom = 0.5f;
public:
	Camera(sf::RenderWindow& window);
	void init();
	sf::View& getView();
	void followCamera(sf::Sprite& mainCharacter);
	void setZoom(Input& input, const std::optional<sf::Event>* event,
		const sf::Event::MouseWheelScrolled* wheel,
		sf::Mouse::Wheel key);
	void setView(sf::View view);
};