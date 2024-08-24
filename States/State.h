#pragma once
#include "../Managers/StateManager.h"

class State
{
protected:
    StateManager* mediator;
    GraphicsManager* graphicsManager;
    std::string name;

public:
    State(std::string nam) : name(nam), mediator(StateManager::getInstance()), graphicsManager(GraphicsManager::getInstance()) {};
    virtual ~State() {};

    void setName(const std::string na) { name = na; }
    std::string getName() { return name; }

    virtual void handleEvent(const sf::Event* event) = 0;
    virtual void draw() = 0;
    virtual void execute() = 0;
};