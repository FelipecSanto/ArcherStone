#include "Platform.h"

namespace Entitys
{
    Platform::Platform(const sf::Vector2f pos, const sf::Vector2f si, Maps::QuadTree* q):
        Entity("PLATFORM", pos, si, q)
    {
    }

    Platform::~Platform()
    {
    }

    void Platform::execute()
    {
    }
}