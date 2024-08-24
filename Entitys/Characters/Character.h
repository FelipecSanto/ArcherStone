#pragma once
#include "../Entity.h"

class Character : public Entity
{
protected:

public:
    Character(std::string ty = "", sf::Vector2f pos = sf::Vector2f(0.0, 0.0), sf::Vector2f si = sf::Vector2f(0.0, 0.0), QuadTree* q = nullptr);
    virtual ~Character();

    virtual void execute() = 0;
};