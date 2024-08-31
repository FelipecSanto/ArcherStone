#include "State.h"
#include "../Managers/StateManager.h"

namespace States
{
    State::State(std::string nam): name(nam), stateManager(Managers::StateManager::getInstance()), graphicsManager(Managers::GraphicsManager::getInstance()) 
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