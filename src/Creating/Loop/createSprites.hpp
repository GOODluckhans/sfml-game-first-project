#pragma once 
#include "../../MainLibraries/main.hpp"
#include "../../../src/TextureManager/textureManager.hpp"

struct ObjData {
	std::string name;
	sf::Vector2f scale;

};

class CreateSprite {
public:
	
	TextureManager textureManager;
	CreateSprite(std::vector<ObjData> &pathFile,sf::RenderWindow& window,const std::string & file,const std::string& nameCreate,const std::string& typeCreate
		, int howMany,int size) {
			
			for (int i = 0; i < howMany; i++) {
				if (pathFile.empty()) {
					continue;
				}
				int random = rand() % pathFile.size();

				std::string F = file;
				size_t pos = F.find("NULL");
				if (pos != std::string::npos) {
					F.replace(pos, 4, pathFile[random].name);
				}
				sf::Sprite sprite(textureManager.get(F));
				if (pathFile[random].scale != sf::Vector2f(0.0f,0.0f)) {
					sprite.setScale(pathFile[random].scale);
				}

				keys.push_back(std::to_string(i) + nameCreate + "_" + pathFile[random].name);

				sprites.emplace(std::to_string(i) + nameCreate + "_" + pathFile[random].name, sprite);
			}

		
	}

	std::string getPathName(const std::string& afterS) {
		for (auto& [key, sprite] : sprites) {
			auto pos = key.find(afterS);
			if (pos != std::string::npos) {
				return key.substr(pos + afterS.length());
			}
		}
		throw std::runtime_error("Sprite not found in map");

	}

	std::unordered_map<std::string, sf::Sprite> sprites;
	std::vector<std::string> keys;

private:


};