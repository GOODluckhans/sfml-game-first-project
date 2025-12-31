#pragma once 
#include "../../MainLibraries/main.hpp"

class Movement {
public:

    template <typename T>
    void moveWithSpeed(T& entity, float speed, float deltaTime, float dirX, float dirY)
    {
        float length = std::sqrt(dirX * dirX + dirY * dirY);
        if (length != 0.f) {
            dirX /= length;
            dirY /= length;
        }

        entity.move({ dirX * speed * deltaTime,
            dirY * speed * deltaTime });
    }

};