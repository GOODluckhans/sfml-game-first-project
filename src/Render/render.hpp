#pragma once
#include "../../MainLibraries/main.hpp"
#include "../Camera/camera.hpp"
enum class RenderLayer {
    BACKGROUND = 0,
    WORLD = 1,
    ENTITY = 2,
    PLAYER = 3,
    OBJECTSPAWN = 4,
    HITBOX = 5,
    UI = 6
};

struct RenderItem {
    sf::RenderStates* states;
    sf::VertexArray* vertexMap;
    sf::Drawable* drawable;
    sf::Transformable* transform;
    sf::FloatRect localBounds;
    int layer = 0;
};

class Render {
public:
    void submit(sf::Drawable& drawable,sf::Transformable& transform,const sf::FloatRect & bounds, int layer) {
        items.push_back({ nullptr,nullptr,&drawable,&transform,bounds, layer });
    }
    void submit(sf::RenderStates& states,sf::VertexArray& vertex, const sf::FloatRect& bounds, int layer, sf::Texture &tileTexture) {
        states.texture = &tileTexture;
        items.push_back({ &states,&vertex,nullptr,nullptr,bounds, layer });
    }
    void render(sf::RenderWindow& window, Camera& camera) {


        sf::FloatRect viewRect(
            camera.getView().getCenter() - camera.getView().getSize() / 2.f,
            camera.getView().getSize()
        );

        std::sort(items.begin(), items.end(),
            [](const RenderItem& a, const RenderItem& b) {
                return a.layer < b.layer;
            });

        for (auto& item : items) {
            // Compute transformed bounds if transform exists
            sf::FloatRect worldBounds = item.localBounds;
            if (item.transform)
                worldBounds = item.transform->getTransform().transformRect(item.localBounds);

            //// Check if item is visible in camera
            //if (!worldBounds.findIntersection(viewRect) && item.layer != static_cast<int>(RenderLayer::UI))
            //    continue;

            // Set view for UI
            if (item.layer == 6)
                window.setView(window.getDefaultView());
            else
                window.setView(camera.getView());

            // Draw the item
            if (item.drawable)
                window.draw(*item.drawable);
            else if (item.vertexMap)
                window.draw(*item.vertexMap, *item.states);
        }

        items.clear(); // important!
    }

private:
    std::vector<RenderItem> items;
};
