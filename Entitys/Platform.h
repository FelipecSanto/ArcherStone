#pragma once
#include "Entity.h"

namespace Entitys
{
    class Platform : public Entity
    {
    private:
        

    public:
        Platform(const sf::Vector2f pos = sf::Vector2f(0.0, 0.0), const sf::Vector2f si = sf::Vector2f(0.0, 0.0), Maps::QuadTree* q = nullptr);
        ~Platform();

        void execute();
    };
}