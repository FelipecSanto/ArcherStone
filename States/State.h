#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../Managers/StateManager.h"
#include "../Managers/EventsManager.h"

namespace States
{
    class State
    {
    protected:
        Managers::StateManager* stateMgr;
        Managers::GraphicsManager* graphicsMgr;
        Managers::EventsManager* eventsMgr;
        std::string name;

    public:
        State(std::string nam);
        virtual ~State();

        void setName(const std::string na);
        std::string getName();

        virtual void draw() = 0;
        virtual void execute() = 0;
    };
}