#pragma once 
#include "../../../MainLibraries/main.hpp"
#include "../../movement/movement.hpp"
#include "../../src/input/input.hpp"
#include "../createHitbox.hpp"
class PlayerHB {
public:
    std::string direction = "UP";
    PlayerHB(sf::RenderWindow& window) : 
        window(window)
    {
        createHb.createRectangle("playerHB");
        hitboxPlayer = &createHb.getHitbox("playerHB");
        
        float centerX = static_cast<float>(window.getSize().x) / 2.f;
        float centerY = static_cast<float>(window.getSize().y) / 2.f;

        // Set the player sprite to the center
        hitboxPlayer->setPosition({ centerX, centerY });

        hitboxPlayer->setSize({ 12.f,12.f });
        hitboxPlayer->setFillColor(sf::Color::Red);

    }

    sf::RectangleShape& getHitbox() {
        return createHb.getHitbox("playerHB");
    }

    void movementPlayerHB(sf::RectangleShape& hitbox,float dt,Input& input,Movement& movement,std::string & direction
    ,bool& playerMove
        ) {
        playerMove = false;

        if (input.isKeyPressed(sf::Keyboard::Key::A)) {
            direction = "LEFT";
            playerMove = true;
            movement.moveWithSpeed(*hitboxPlayer, 500.f, dt, -1.f, 0.0f);
        }
        if (input.isKeyPressed(sf::Keyboard::Key::W)) {
            direction = "UP";
            playerMove = true;

            movement.moveWithSpeed(*hitboxPlayer, 500.f, dt, 0.0f, -1.f);
        }
        if (input.isKeyPressed(sf::Keyboard::Key::D)) {
            playerMove = true;

            direction = "RIGHT";
            movement.moveWithSpeed(*hitboxPlayer, 500.f, dt, 1.f, 0.0f);
        }
        if (input.isKeyPressed(sf::Keyboard::Key::S)) {
            playerMove = true;
            direction = "DOWN";
            playerMove = true;

            movement.moveWithSpeed(*hitboxPlayer, 500.f, dt, 0.0f, 1.f);
        }


    }
    sf::RectangleShape* hitboxPlayer = nullptr;

private:
    sf::RenderWindow& window;
    CreateHitbox createHb;


};