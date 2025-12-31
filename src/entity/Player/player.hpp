#pragma once 
#include "../../../MainLibraries/main.hpp"
#include "../../../src/Creating/Once/createSprites.hpp"
#include "../../hitbox/PlayerHb/playerHb.hpp"
class Player {
private:
    CreateSprite1 createSprite;  // declare member
  
    sf::Sprite* playerSprite = nullptr;
    std::vector<std::string> idk;
    sf::RenderWindow& window;
public:
    bool playerMove = false;
    sf::IntRect spriteAnimChar;

    PlayerHB playerHB;
    Player(sf::RenderWindow& window)
        : createSprite(window,"assets/Textures/Entity/Player/player.png", "player") 
        ,spriteAnimChar({ 0, 0 }, { 102, 152 })
        , window(window),playerHB(window)
    {
       playerSprite = &getSprite();
       // Get the center of the window
       float centerX = static_cast<float>(window.getSize().x) / 2.f;
       float centerY = static_cast<float>(window.getSize().y) / 2.f;

       // Set the player sprite to the center
       playerSprite->setPosition({ centerX, centerY});

        playerSprite->setScale({ 0.3f,0.3f });

    
       
    }


    sf::Sprite& getSprite() {
        return createSprite.getSprites("player");
    }

    void update() {
        sf::FloatRect playerBounds = playerSprite->getGlobalBounds();

        playerSprite->setPosition({
                playerHB.getHitbox().getPosition().x + playerHB.getHitbox().getSize().x * 0.5f - playerBounds.size.x * 0.5f,
                   (  playerHB.getHitbox().getPosition().y + playerHB.getHitbox().getSize().y * 0.5f - playerBounds.size.y * 0.5f) - 10.f
            });

    }
};
