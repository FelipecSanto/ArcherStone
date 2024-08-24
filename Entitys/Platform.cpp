#include "Platform.h"

Platform::Platform(const sf::Vector2f pos, const sf::Vector2f si, QuadTree* q):
    Entity("PLATFORM", pos, si, q)
{
}

Platform::~Platform()
{
}

void Platform::execute()
{
}