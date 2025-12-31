#pragma once 
#include "../../MainLibraries/main.hpp"

struct WindowConfig {
	static inline unsigned int width = 832;
	static inline unsigned int height = 512;
	static inline std::string title = "Hanif";
	static inline unsigned int framerateLimit = 60;
};


class Window {
public:
	Window(unsigned int WIDTH , unsigned int HEIGHT,const std::string& title);
	sf::RenderWindow& getWindow();

	bool isOpen() const;

	void clear(const sf::Color& color = sf::Color::Black);
	void display();
private:
	sf::RenderWindow window;

};