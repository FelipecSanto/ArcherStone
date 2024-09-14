#include "Observer.h"

namespace Observers
{
    Observer::Observer():
    activated(true),
    stateMgr(Managers::StateManager::getInstance())
    {
    }

    Observer::~Observer()
    {
    }

    void Observer::setActivated(const bool active)
    {
        activated = active;
    }

    const bool Observer::getActivated() const
    {
        return activated;
    }
}