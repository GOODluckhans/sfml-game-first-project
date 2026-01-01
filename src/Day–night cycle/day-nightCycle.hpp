#pragma once 
#include "../../MainLibraries/main.hpp"

enum class Cycle {
	Night,
	Day

};
//after eat letme fix and add cycle every 20 mins

class Day_NightCycle {
private:
	int hour;
	int dayDuration;
	sf::Clock clock;
	float dt = 0;
	float timer = 0;
	Cycle currentCycle = Cycle::Day;
	sf::RectangleShape Overlay;
	sf::RenderWindow& window;

public:
	Day_NightCycle(int dayDuration,sf::RenderWindow& window) :
	dayDuration(dayDuration) , hour(0) , window(window){}
	void updateTime() {
		dt = clock.restart().asSeconds();
		timer += dt;
		if (timer >= (float)dayDuration) {
			timer -= (float)dayDuration;
			hour = (hour + 1) % 24;
		}
	}

	void update(sf::RectangleShape& pHitbox){
		changingTime();
		createDraw(pHitbox);
	}

	void changingTime() {
		if (hour < 6 || hour > 18) {
			currentCycle = Cycle::Night;
		}
		else {
			currentCycle = Cycle::Day;
		}


	}

	void createDraw(sf::RectangleShape& pHitbox) {
		

		Overlay.setPosition(pHitbox.getPosition());
		Overlay.setSize({ static_cast<float>(window.getSize().x * 6),static_cast<float>( window.getSize().y*6)});
	
		Overlay.setOrigin({Overlay.getSize().x / 2.f , Overlay.getSize().y / 2});



		if (currentCycle == Cycle::Night) {
			Overlay.setFillColor(sf::Color(0, 0, 0, 128));
		}
		else {
			Overlay.setFillColor(sf::Color(255,255,0,26));
		}
	}

	sf::RectangleShape& getRectangle() {
		return Overlay;
	}

	std::string getCurrentTIme() {
		return std::to_string(hour) + ":00";
	}
};