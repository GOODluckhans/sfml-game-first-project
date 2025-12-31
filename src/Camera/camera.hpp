#pragma once 
#include "../../MainLibraries/main.hpp"

class Camera {
private:
	sf::View view;
	float followSpeed = 5.f;
	sf::RenderWindow& window;  // reference
public:
	Camera(sf::RenderWindow& window);
	void init();
	sf::View& getView();
	void followCamera(sf::Sprite& mainCharacter);

	void setView(sf::View view);
};