#include "State.h"
#include "../Managers/StateManager.h"
#include "../Managers/EventsManager.h"

namespace States
{
    State::State(std::string nam): name(nam), stateMgr(Managers::StateManager::getInstance()), graphicsMgr(Managers::GraphicsManager::getInstance()) 
    {
    }

    State::~State() {

    }

    void State::setName(const std::string na) { 
        name = na; 
    }

    std::string State::getName() { 
        return name; 
    }
}