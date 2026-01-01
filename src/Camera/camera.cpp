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
	view.zoom(cameraZoom);
}

void Camera::setView(sf::View view) {
	window.setView(view);
}



sf::View& Camera::getView() {
	return view;
}


void Camera::setZoom(Input& input, const std::optional<sf::Event>* event,
	const sf::Event::MouseWheelScrolled* wheel,
	sf::Mouse::Wheel key){
	if (input.isWheelPressedEventUp(event,wheel,key)) {

		if (cameraZoom <= 0.5f) return;
		cameraZoom -= 0.25f;

	}
	else if (input.isWheelPressedEventDown(event, wheel, key)) {
		if (cameraZoom >= 5.f) return;
		cameraZoom += 0.25f;
	}
}