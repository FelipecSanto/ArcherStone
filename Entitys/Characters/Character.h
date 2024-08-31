#pragma once
#include "../Entity.h"

namespace Entitys
{
    namespace Characters
    {
        class Character : public Entity
        {
        protected:
            

        public:
            Character(std::string ty = "", sf::Vector2f pos = sf::Vector2f(0.0, 0.0), sf::Vector2f si = sf::Vector2f(0.0, 0.0), Maps::QuadTree* q = nullptr);
            virtual ~Character();

            virtual void execute() = 0;
        };
    }
}