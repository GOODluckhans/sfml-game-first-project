#pragma once
#include "../../MainLibraries/main.hpp"
class TextureManager {
public:
    std::unordered_map<std::string, sf::Texture> textures;

    sf::Texture& get(const std::string& path) {
        if (!textures.contains(path)) {
            textures[path].loadFromFile(path);
        }
        return textures[path];
    }
};
