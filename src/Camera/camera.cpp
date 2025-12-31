// camera.cpp
#include "camera.hpp"

Camera::Camera(sf::RenderWindow& window) : window(window) {}
void Camera::followCamera(sf::Sprite& mainCharacter) {
	//float mapWidth = window.getSize().x;   // total width of your world
	//float mapHeight = window.getSize().y;  // total height of your world
	sf::Vector2f camPos = mainCharacter.getPosition();
	//float halfW = view.getSize().x / 2.f;
	//float halfH = view.getSize().y / 2.f;

	//camPos.x = std::max(camPos.x, halfW);
	//camPos.x = std::min(camPos.x, mapWidth - halfW);
	//camPos.y = std::max(camPos.y, halfH);
	//camPos.y = std::min(camPos.y, mapHeight - halfH);

	view.setCenter(camPos);

}

void Camera::init() {
	view.setSize(
		{ (float)window.getSize().x,
		(float)window.getSize().y }
	);
	view.zoom(5.f);
}

void Camera::setView(sf::View view) {
	window.setView(view);
}



sf::View& Camera::getView() {
	return view;
}