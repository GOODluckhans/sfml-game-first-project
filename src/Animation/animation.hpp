#pragma once 
#include "../../MainLibraries/main.hpp"

class Animation {
public:
	Animation(sf::IntRect& SpriteRect,bool& isMove);
	void setTextureRect(sf::Sprite& sprite);
	void animationRun(const std::string& direction ,sf::Sprite& sprite, int maximumX = 306, int addingX = 102,
		int rightStart = 456, int leftStart = 304, int upStart = 152, int downStart = 0);
	void animationStop(sf::Sprite& character, const std::string& lastDirMove, int width = 102, int height = 152,
		int xDown = 0, int xTop = 0, int xLeft = 0, int xRight = 306,
		int yDown = 0, int yTop = 152, int yLeft = 304, int yRight = 456);

private:
	sf::Clock clock;
	sf::IntRect SpriteRect;
	bool& isMove;
};