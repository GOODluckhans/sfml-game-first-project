#include "MainLibraries/main.hpp"
#include "src/window/window.hpp"
#include "src/Render/render.hpp"
#include "src/System/objSystem.hpp"
#include "src/Camera/camera.hpp"
int main() {
	std::srand(static_cast<unsigned>(std::time(nullptr))); // seed once

	Window window(WindowConfig::width, WindowConfig::height,WindowConfig::title);
	window.getWindow().setFramerateLimit(WindowConfig::framerateLimit);
	//render class
	Render render	;
	//entity system
	ObjSystem objSystem(window.getWindow());

	//input
	Input input;
	//movement
	Movement movement;
	//Camera
	Camera camera(window.getWindow());
	camera.init();
	Collision collision;
	sf::Clock clock;
	float dt = 0;


	while (window.isOpen())
	{
		dt = clock.restart().asSeconds();
		std::optional<sf::Event> event; // <-- move it here

		while ((event = window.getWindow().pollEvent())) {

			if (event->is<sf::Event::Closed>()) {
				window.getWindow().close();
			}
			if (auto keyboard = event->getIf<sf::Event::KeyPressed>()) {
				if (input.isKeyPressedEvent(&event, keyboard ,sf::Keyboard::Scancode::Escape)) {
					std::cout << "you are clicking Esc \n";
					window.getWindow().close();
				}

			}
			

		}

		//update
		objSystem.update(dt,input, movement);
		//collision
		objSystem.viewSet(camera);

		objSystem.handleCollision(collision);
		
		window.getWindow().clear();
		objSystem.renderEntity(window.getWindow(),render);
		render.render(window.getWindow(),camera);
		window.getWindow().display();

	}


	return 0;
}


