#include "animation.hpp"
Animation::Animation(sf::IntRect& SpriteRect,bool& isMove) :SpriteRect(SpriteRect) ,isMove(isMove) {}
void Animation::setTextureRect(sf::Sprite& sprite) {
	sprite.setTextureRect(SpriteRect);
}
void Animation::animationRun(const std::string& direction, sf::Sprite& sprite, int maximumX, int addingX,
	int rightStart, int leftStart, int upStart, int downStart
) {
	if (!isMove) {
		animationStop(sprite,direction);
		return;
	}
	if (direction == "RIGHT") {
		SpriteRect.position.y = rightStart;
		if (clock.getElapsedTime().asSeconds() > 0.25f) {
			if (SpriteRect.position.x == maximumX) {  // use `.left`, not `.position.x`
				SpriteRect.position.x = 0;
			}
			else {
				SpriteRect.position.x += addingX;
			}
			sprite.setTextureRect(SpriteRect);
			clock.restart();
		}
	}
	else if (direction == "LEFT") {
		SpriteRect.position.y = leftStart;

		if (clock.getElapsedTime().asSeconds() > 0.25f) {
			if (SpriteRect.position.x == maximumX) {  // use `.left`, not `.position.x`
				SpriteRect.position.x = 0;
			}
			else {
				SpriteRect.position.x += addingX;
			}
			sprite.setTextureRect(SpriteRect);
			clock.restart();
		}
	}
	else if (direction == "UP") {
		SpriteRect.position.y = upStart;

		if (clock.getElapsedTime().asSeconds() > 0.25f) {
			if (SpriteRect.position.x == maximumX) {  // use `.left`, not `.position.x`
				SpriteRect.position.x = 0;
			}
			else {
				SpriteRect.position.x += addingX;
			}
			sprite.setTextureRect(SpriteRect);
			clock.restart();
		}
	}
	else if (direction == "DOWN") {
		SpriteRect.position.y = downStart;

		if (clock.getElapsedTime().asSeconds() > 0.25f) {
			if (SpriteRect.position.x == maximumX) {  // use `.left`, not `.position.x`
				SpriteRect.position.x = 0;
			}
			else {
				SpriteRect.position.x += addingX;
			}
			sprite.setTextureRect(SpriteRect);
			clock.restart();
		}
	}
	
}



void Animation::animationStop(sf::Sprite& sprite, const std::string& lastDirMove, int width , int height ,
	int xDown , int xTop , int xLeft , int xRight ,
	int yDown , int yTop, int yLeft , int yRight)  {

	if (lastDirMove == "DOWN")
		SpriteRect = sf::IntRect({ xDown, yDown }, { width, height });
	else if (lastDirMove == "UP")
		SpriteRect = sf::IntRect({ xTop, yTop }, { width, height });
	else if (lastDirMove == "LEFT")
		SpriteRect = sf::IntRect({ xLeft, yLeft }, { width, height });
	else if (lastDirMove == "RIGHT")
		SpriteRect = sf::IntRect({ xRight, yRight }, { width, height });

	sprite.setTextureRect(SpriteRect);

}


void Animation::ParticleEffect() {
	
}