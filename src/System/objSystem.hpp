#pragma once 
#include "../../MainLibraries/main.hpp"
#include "../entity/Player/player.hpp"
#include "../Render/render.hpp"
#include "../World/main/Worlds.hpp"
#include "../Physic/Collision/collision.hpp"
#include "../Camera/camera.hpp"
#include "../../src/Animation/animation.hpp"
#include "../../src/ObjectSpawner/treeSpawner/Tree.hpp"

struct layer {
	int BACKGROUND = 0;
	int	WORLD = 1;
	int	ENTITY = 2;
	int	PLAYER = 3;
	int	OBJECTSPAWN = 4;
	int	HITBOX = 5;
	int	UI = 6;
	
};

class ObjSystem {
private:
	Player player;
	Animation animation;
	Tree tree;
	MainMap mainMap;
	//for animation
	layer layerInt;
	layer NormalLayer;
public:
	ObjSystem(sf::RenderWindow& window);
	void update(float dt,Input &input,Movement& movement);
	void renderEntity(sf::RenderWindow& window,Render& render);
	void viewSet(Camera& camera);
	void handleCollision(Collision& collision);
};