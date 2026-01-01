#pragma once 
#include "../../MainLibraries/main.hpp"
#include "../../src/TextureManager/textureManager.hpp"
enum class WeatherData {
    Sunny ,
    Rainy
};



class Weather {
private:TextureManager textureManager;
    WeatherData data;
    sf::Clock spawnClock;
    int random = 2;
    sf::Clock moveClock;
    float dt = 0;
    std::vector<sf::Clock> splashesClock;
    std::string waterSplashFile = "assets/Textures/Particles/waterSplash.png";
    WeatherData currentWeather = WeatherData::Sunny;
public:
    std::vector<sf::RectangleShape> rainFalls;
    std::vector<sf::Sprite>RainSplashes;
     Weather() {}
    void WeatherActive() {
        if (spawnClock.getElapsedTime().asSeconds() >= 5.f) {
            random = rand() % 100;
            gettingWeather();
            spawnClock.restart();
        }
    }

    void update(sf::RectangleShape& pHitbox) {
        dt = moveClock.restart().asSeconds();
        if (currentWeather == WeatherData::Rainy) {
            sf::RectangleShape Particle;
            Particle.setSize({3.5f ,static_cast<float>(rand() % 30 + 1)});

            Particle.setRotation(sf::degrees(25.f));
            Particle.setPosition({(float)(rand() % 1000 * 9),- 20.f});
            Particle.setFillColor(sf::Color::Blue);

            sf::Sprite waterSplash(textureManager.get(waterSplashFile));
            waterSplash.setScale({0.5f,0.5f});
            waterSplash.setPosition({(float)(rand() % 1000 * 9), (float)(rand() % 1000 * 5) });

            RainSplashes.push_back(waterSplash);

            rainFalls.push_back(Particle);

            splashesClock.emplace_back();

            for (auto i = 0; i < RainSplashes.size(); i++) {

                if (splashesClock.size() != RainSplashes.size()) {
                    splashesClock.resize(RainSplashes.size());
                }

                if (splashesClock[i].getElapsedTime().asSeconds() >= 0.1f) {
                    RainSplashes.erase(RainSplashes.begin() + i);
                    splashesClock[i].restart();
                }
            }

            for (auto& a : rainFalls) {
                float angleDegrees = -25.f;
                float angleRadians = angleDegrees * 3.14159265f / 180.f; // convert to radians

                a.move({ 400.f * std::sin(angleRadians) * dt, 600.f * std::cos(angleRadians) * dt });

            }

            for (auto i = 0; i < rainFalls.size(); i++) {
                if (pHitbox.getPosition().y * 4.f < rainFalls[i].getPosition().y) {
                    rainFalls.erase(rainFalls.begin() + i);
                }
            }

        }
        else if (currentWeather == WeatherData::Sunny) {
            rainFalls.clear();
            RainSplashes.clear();
        }

      
    
    }   

   

    void gettingWeather() {
        if (random < 1) {
            currentWeather = WeatherData::Sunny;
        }
        else if (random < 100) {
            currentWeather = WeatherData::Rainy;
        }
    }
    
};