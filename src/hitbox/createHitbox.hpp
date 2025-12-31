#pragma once
#include "../../MainLibraries/main.hpp"

class CreateHitbox {
public:
	void createRectangle(const std::string& name) {
		sf::RectangleShape hitbox;
		rectangles.emplace(name,hitbox);
	}
	sf::RectangleShape& getHitbox(const std::string& nameCreate) {
		auto it = rectangles.find(nameCreate);
		if (it != rectangles.end()) {

			return it->second;

		}
		throw std::runtime_error("Rectangle not found: " + nameCreate);
	}

private:
	std::unordered_map<std::string, sf::RectangleShape> rectangles;

};