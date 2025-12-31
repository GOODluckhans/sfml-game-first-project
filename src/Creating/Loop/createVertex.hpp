#pragma once 
#include "../../../MainLibraries/main.hpp"
struct TreeTile {
    sf::Vector2f pos;        
    sf::Vector2f size;       
    sf::ConvexShape collider;
};
class Vertex {
private:
public:
    void setVertexMap(
        sf::VertexArray& vertexMap,
        const sf::Vector2f& worldPos,
        const sf::Vector2f& tileSize,
        const sf::Vector2u texSize,
        int& index,
        std::vector<TreeTile>& treeTiles,
        const sf::Texture& treeTexture
    ) {
        // Create tree tile
        TreeTile tile;

        tile.pos = worldPos;
        tile.size = tileSize;

        tile.collider.setPointCount(4);
        tile.collider.setPoint(0, { 0.f, tile.size.y });
        tile.collider.setPoint(1, { tile.size.x, tile.size.y });
        tile.collider.setPoint(2, { tile.size.x * 0.8f, 0.f });
        tile.collider.setPoint(3, { tile.size.x * 0.2f, 0.f });
        tile.collider.setPosition(tile.pos);

        treeTiles.push_back(tile);

        // ---- first triangle ----
        vertexMap[index + 0].position = tile.pos;                       // top-left
        vertexMap[index + 1].position = tile.pos + sf::Vector2f(tile.size.x, 0.f);  // top-right
        vertexMap[index + 2].position = tile.pos + tile.size;           // bottom-right

        vertexMap[index + 0].texCoords = { 0.f, 0.f };                 // top-left
        vertexMap[index + 1].texCoords = { (float)texSize.x, 0.f };    // top-right
        vertexMap[index + 2].texCoords = { (float)texSize.x, (float)texSize.y }; // bottom-right

        // second triangle
        vertexMap[index + 3].position = tile.pos;
        vertexMap[index + 4].position = tile.pos + tile.size;
        vertexMap[index + 5].position = tile.pos + sf::Vector2f(0.f, tile.size.y);

        vertexMap[index + 3].texCoords = { 0.f, 0.f };
        vertexMap[index + 4].texCoords = { (float)texSize.x, (float)texSize.y };
        vertexMap[index + 5].texCoords = { 0.f, (float)texSize.y };


        index += 6; // move to next tree
    }



    void setVertexMap(sf::VertexArray& vertexMap, const sf::Vector2f& worldPos, const sf::Vector2f& tileSize, const sf::Vector2u texSize, int& index) {
        vertexMap[index + 0].position = { worldPos };
        vertexMap[index + 1].position = { worldPos.x + tileSize.x, worldPos.y };
        vertexMap[index + 2].position = { worldPos.x + tileSize.x, worldPos.y + tileSize.y };

        vertexMap[index + 0].texCoords = { 0.f, 0.f };
        vertexMap[index + 1].texCoords = { (float)texSize.x, 0.f };
        vertexMap[index + 2].texCoords = { (float)texSize.x, (float)texSize.y };

        // ---- second triangle ----
        vertexMap[index + 3].position = { worldPos };
        vertexMap[index + 4].position = { worldPos.x + tileSize.x, worldPos.y + tileSize.y };
        vertexMap[index + 5].position = { worldPos.x, worldPos.y + tileSize.y };

        vertexMap[index + 3].texCoords = { 0.f, 0.f };
        vertexMap[index + 4].texCoords = { (float)texSize.x, (float)texSize.y };
        vertexMap[index + 5].texCoords = { 0.f, (float)texSize.y };
        index += 6; // ?? move to next tile

    }

};