#include "objSystem.hpp"

ObjSystem::ObjSystem(sf::RenderWindow& window) :
	mainMap(window), player(window), animation(player.spriteAnimChar, player.playerMove),
	tree(window)
{
}

void ObjSystem::update(float dt, Input& input, Movement& movement) {
	player.update();
	//std::cout << "PLAYER : " << layerInt.PLAYER << '\n' <<
	//	"OBJECT : " << layerInt.OBJECTSPAWN << '\n';;
	player.playerHB.movementPlayerHB(player.playerHB.getHitbox(), dt, input, movement, player.playerHB.direction, player.playerMove);
	animation.animationRun(player.playerHB.direction, player.getSprite());
}

void ObjSystem::renderEntity(sf::RenderWindow& window, Render& render) {
	//FOR STATIC DRAW 
	render.submit(mainMap.states,mainMap.vertexMap,mainMap.getBounds(mainMap.vertexMap),layerInt.WORLD,mainMap.tileTexture);
	//mainMap.draw(window);

	render.submit(player.getSprite(), player.getSprite(), player.getSprite().getGlobalBounds(), layerInt.PLAYER);
	render.submit(player.playerHB.getHitbox(), player.playerHB.getHitbox(), player.playerHB.getHitbox().getGlobalBounds(), layerInt.HITBOX);



	for (auto& [key, hitboxPtr] : tree.treeHitboxes) {
		render.submit(*hitboxPtr, *hitboxPtr, hitboxPtr->getGlobalBounds(), layerInt.HITBOX);
	}

	std::vector<sf::Sprite*> sortedSprites;
	for (auto& [key, spritePtr] : tree.trees) {
		sortedSprites.push_back(spritePtr);
	}

	std::sort(sortedSprites.begin(), sortedSprites.end(),
		[](sf::Sprite* a, sf::Sprite* b) {
			return a->getPosition().y < b->getPosition().y;
		});

	// Render from sorted vector
	for (auto* spritePtr : sortedSprites) {
		render.submit(*spritePtr, *spritePtr, spritePtr->getLocalBounds(), layerInt.OBJECTSPAWN);
	}

}

void ObjSystem::handleCollision(Collision& collision) {

	auto getCenter = [&](const sf::Sprite& r) -> sf::Vector2f {
		sf::FloatRect b;


		if constexpr (requires { r.getGlobalBounds(); }) {
			b = r.getGlobalBounds();

		}

		return sf::Vector2f(
			b.position.x + b.size.x * 0.5f,
			b.position.y + b.size.y * 0.85f
		);
		};

	auto RemovingObjct = [&](const bool& isRemovedByEnvironment, auto& objInventory, auto* main, const std::string& key

		) {
			for (auto it = objInventory.begin();
				it != objInventory.end();) {
				if (isRemovedByEnvironment && !key.empty()) {
					std::string s = it->first;
					size_t pos = s.find_last_of('_');
					if (pos != std::string::npos) {
						s = s.substr(pos + 1);
					}

					if (key.find(s) != std::string::npos) { ++it;  continue; }


					auto* objSprite = it->second;
					sf::FloatRect bound = objSprite->getGlobalBounds();
					if (collision.isColliding(bound, *main)) {
						it = objInventory.erase(it);
						//std::cout << objInventory.size() << '\n';
					}
					else {
						it++;
					}

				}

			}

		};


	for (auto& [key, world] : mainMap.worlds) {
		RemovingObjct(true, tree.trees, world, key);
		RemovingObjct(true, tree.treeHitboxes, world, key);
	}

	auto solidColliding = [&](auto& obj1, auto& obj2) {
		collision.ifColliding(obj1, obj2, true);

		};

	for (auto& [key, treeHB] : tree.treeHitboxes) {
		if (collision.isColliding(player.playerHB.getHitbox(), *treeHB)) {
			solidColliding(player.playerHB.getHitbox(), *treeHB);
			std::cout << key << '\n';
		}
	}

	
	auto depth = [&](auto& main, auto& obj,
		int& mainLayer, int& objLayer
		)
		{
			sf::Vector2f mainCenter = getCenter(main);
			sf::Vector2f objCenter = getCenter(obj);

			if (!collision.isColliding(main, obj)) {

				return;
			}

			if (mainCenter.y > objCenter.y) {

				// JUST ABOVE
				mainLayer = objLayer;
				objLayer = objLayer - 1;
			}
			else {
				mainLayer = objLayer - 1;
				objLayer = objLayer;
				// JUST ABOVE

			}
		};

	layerInt.BACKGROUND = NormalLayer.PLAYER;
	layerInt.PLAYER = NormalLayer.PLAYER;
	layerInt.OBJECTSPAWN = NormalLayer.OBJECTSPAWN;
	layerInt.WORLD = NormalLayer.WORLD;
	layerInt.ENTITY = NormalLayer.ENTITY;
	layerInt.UI = NormalLayer.UI;
	layerInt.HITBOX = NormalLayer.HITBOX;

	for (auto& [key, treeSprite] : tree.trees) {
		depth(player.getSprite(), *treeSprite, layerInt.PLAYER, layerInt.OBJECTSPAWN
		);
	}




	for (auto it = tree.treeHitboxes.begin();
		it != tree.treeHitboxes.end();) {
		bool hasCollision = false;

		auto* objSprite = it->second;
		for (auto& [key, treeSprite] : tree.trees) {
			sf::FloatRect bound = objSprite->getGlobalBounds();
			if (collision.isColliding(bound, *treeSprite)) {
				hasCollision = true;
				break;
				//std::cout << objInventory.size() << '\n';
			}
		}
			if (!hasCollision) {
				it = tree.treeHitboxes.erase(it);
			}
			else {
				++it;
			}

	}

}

void ObjSystem::viewSet(Camera& camera) {
	camera.followCamera(player.getSprite());

}