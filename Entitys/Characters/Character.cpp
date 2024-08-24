#include "Character.h"

Character::Character(std::string ty, sf::Vector2f pos, sf::Vector2f si, QuadTree* q):
    Entity(ty, pos, si, q)
{
}

Character::~Character()
{
}
