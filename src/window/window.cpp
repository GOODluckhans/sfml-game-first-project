#include "window.hpp"

Window::Window(unsigned int WIDTH, unsigned int HEIGHT, const std::string& title) :
	window(sf::VideoMode({ WIDTH, HEIGHT }), title, sf::Style::Close)
{
	
}
sf::RenderWindow& Window::getWindow() {
	return window;
}

bool Window::isOpen() const { return window.isOpen(); }

void Window::clear(const sf::Color& color) {
	getWindow().clear(color);
}
void Window::display() {
	getWindow().display();
}