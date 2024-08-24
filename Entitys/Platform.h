#pragma once
#include "Entity.h"

class Platform : public Entity
{
private:
    

public:
    Platform(const sf::Vector2f pos = sf::Vector2f(0.0, 0.0), const sf::Vector2f si = sf::Vector2f(0.0, 0.0), QuadTree* q = nullptr);
    ~Platform();

    void colision(Entity* otherEntity, sf::FloatRect instersects) {}

    void execute();
};