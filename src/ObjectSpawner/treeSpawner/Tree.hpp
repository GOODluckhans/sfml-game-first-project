#pragma once 
#include "../../TextureManager/textureManager.hpp"
#include "../../MainLibraries/main.hpp"
#include "../../Creating/Loop/createSprites.hpp"
#include "../../hitbox/createHitbox.hpp"
class Tree {
private:
	TextureManager textureManager;
	int spanwCount = 50;
	std::vector<ObjData> pathFile = { 
		{"TREE_Dead",sf::Vector2f(5.f,5.f)}
};

	//Vertex createVertex;
	CreateHitbox createHitbox;
	CreateSprite createSprite;//should be bottom

public:
	std::vector<TreeTile> treeTiles;

	sf::RenderStates states;
	sf::VertexArray vertexMap;
	sf::Texture tileTexture;
	std::unordered_map<std::string,sf::Sprite*> trees;
	std::unordered_map<std::string, sf::RectangleShape*> treeHitboxes;

	Tree(sf::RenderWindow & window)
		:createSprite(pathFile,window,"assets/Textures/objects/Tree/NULL.png","tree","sprite"
			, static_cast<int>(spanwCount),pathFile.size())
	{
		for (auto i = 0; i < spanwCount; i++) {
			auto& key = createSprite.keys[i];
		
			auto it = createSprite.sprites.find(key);
			if (it == createSprite.sprites.end()) {
				throw std::runtime_error("Tree sprite 'tree' not found!");
			}
			sf::Sprite& sprite = it->second;
		
			createHitbox.createRectangle(it->first);
			sf::RectangleShape& hitboxTree = createHitbox.getHitbox(it->first);
		
		
			float x = static_cast<float>(rand() % window.getSize().x * 10.f);
			float y = static_cast<float>(rand() % window.getSize().y * 7.f);
		
			
			sprite.setPosition({ x, y });
		
			sf::Vector2f spritePos = sprite.getPosition();
			sf::FloatRect spriteBound = sprite.getGlobalBounds();
			sf::Vector2f hitboxSize = { 40.f, 25.f };
			hitboxTree.setSize(hitboxSize);
		
			sf::Vector2f spriteCenter(
				spritePos.x + spriteBound.size.x / 2.f,
				spritePos.y + spriteBound.size.y / 2.f
			);
		
			hitboxTree.setPosition(
				spriteCenter - sf::Vector2f((hitboxSize.x / 2.f) - 5.f, (hitboxSize.y / 2.f) - 100.f)
			);
		
			treeHitboxes.emplace(key,&hitboxTree);
			trees.emplace(key,&sprite);//
		
		//why gone
		}


	
	}


};