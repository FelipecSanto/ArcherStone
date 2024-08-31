#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace Managers {
    class StateManager;
    class GraphicsManager;
}

namespace States
{
    class State
    {
    protected:
        Managers::StateManager* stateManager;
        Managers::GraphicsManager* graphicsManager;
        std::string name;

    public:
        State(std::string nam);
        virtual ~State();

        void setName(const std::string na);
        std::string getName();

        virtual void handleEvent(const sf::Event* event) = 0;
        virtual void draw() = 0;
        virtual void execute() = 0;
    };
}