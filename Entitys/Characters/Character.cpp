#include "Character.h"

namespace Entitys
{
    namespace Characters
    {
        Character::Character(std::string ty, sf::Vector2f pos, sf::Vector2f si, Maps::QuadTree* q):
            Entity(ty, pos, si, q)
        {
        }

        Character::~Character()
        {
        }
    }
}
