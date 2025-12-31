#pragma once 
#include "../../../MainLibraries/main.hpp"
#include "../../../src/Creating/Loop/createVertex.hpp"
#include "../../src/window/window.hpp"
class MainMap {
private:
  std::vector<std::string> pathFile = {
        "assets/Textures/Maps/drought.png"
    
  };
    std::string name = "";
    unsigned int rows = 10;
    unsigned int cols = 10;

    Vertex createVertex;

    sf::Sprite* mapSprite = nullptr;
public:
    sf::RenderStates states;
    sf::Texture tileTexture;
    sf::VertexArray vertexMap;

    std::unordered_map<std::string,sf::Sprite*> worlds;

    MainMap(sf::RenderWindow & window)
    {
        vertexMap.setPrimitiveType(sf::PrimitiveType::Triangles);
        vertexMap.resize(rows * cols * 6); // ?? IMPORTANT

     
        int index = 0;

        tileTexture.loadFromFile(pathFile[0]);


        for (unsigned int y = 0; y < rows; y++)
        {
            for (unsigned int x = 0; x < cols; x++)
            {
            
                sf::Vector2u texSize = tileTexture.getSize();


                sf::Vector2f tileSize{ static_cast<float>(texSize.x), static_cast<float>(texSize.y) };

                sf::Vector2f worldPos(x * tileSize.x, y * tileSize.y);
                createVertex.setVertexMap(vertexMap,worldPos,tileSize,texSize,index);
                // ---- first triangle ----
              
            }
        }
    }

    std::vector<std::string> cannotSpawnTree = { "water" };

    void draw(sf::RenderWindow& window)
    {
 
        states.texture = &tileTexture;
        window.draw(vertexMap, states);
    }

    sf::FloatRect getBounds(const sf::VertexArray& va)
    {
        if (va.getVertexCount() == 0)
            return {};

        float left = va[0].position.x;
        float top = va[0].position.y;
        float right = left;
        float bottom = top;

        for (size_t i = 1; i < va.getVertexCount(); ++i)
        {
            const auto& p = va[i].position;

            if (p.x < left)   left = p.x;
            if (p.y < top)    top = p.y;
            if (p.x > right)  right = p.x;
            if (p.y > bottom) bottom = p.y;
        }

        return sf::FloatRect({
            left,
            top }, {
            right - left,
            bottom - top }
        );
    }


  
};
