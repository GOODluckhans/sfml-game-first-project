#pragma once 
#include "../../MainLibraries/main.hpp"
#include "../../../src/TextureManager/textureManager.hpp"
class CreateSprite1 {
public:
	TextureManager textureManager;

	CreateSprite1(sf::RenderWindow& window,const std::string & file,const std::string& nameCreate 
		) {
			sf::Sprite sprite(textureManager.get(file));
			sprites.emplace(nameCreate, sprite);
		
	}
	sf::Sprite& getSprites(const std::string& nameCreate) {

		auto it = sprites.find(nameCreate);
		if (it != sprites.end()) {
		
				return it->second;
			
		}
		throw std::runtime_error("Sprite not found: " + nameCreate);
	}

private:
	std::unordered_map<std::string, sf::Sprite> sprites;



};