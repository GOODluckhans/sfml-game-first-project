#pragma once 
#include "../../MainLibraries/main.hpp"
#include "../entity/Player/player.hpp"
#include "../Render/render.hpp"
#include "../World/main/Worlds.hpp"
#include "../Physic/Collision/collision.hpp"
#include "../Camera/camera.hpp"
#include "../../src/Animation/animation.hpp"
#include "../../src/ObjectSpawner/treeSpawner/Tree.hpp"
#include "../../src/Day–night cycle/day-nightCycle.hpp"
#include "../../src/weather/weatherSystem.hpp"

struct layer {
	int BACKGROUND = 0;
	int	WORLD = 1;
	int	ENTITY = 2;
	int WEATHER = 3;
	int	PLAYER = 4;
	int	OBJECTSPAWN = 5;
	int	HITBOX = 6;
	int CYCLE = 7;
	int	UI = 8;
	
};

class ObjSystem {
private:
	Animation animation;
	Tree tree;
	MainMap mainMap;
	//for animation
	layer layerInt;
	layer NormalLayer;
	Player player;

	//day night cycle
	Day_NightCycle dayNightCycle;

	//wheater
	Weather weather;
public:
	ObjSystem(sf::RenderWindow& window);
	void update(float dt,Input &input,Movement& movement);
	void renderEntity(sf::RenderWindow& window,Render& render);
	void viewSet(Camera& camera);
	void handleCollision(Collision& collision);
};