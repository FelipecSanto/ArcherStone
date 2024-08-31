#pragma once
#include "GraphicsManager.h"
#include "../States/State.h"
#include <map>
#include <string>

namespace Managers
{
    class StateManager
    {
    private:
        std::map<std::string, States::State*> statesMap;
        std::string currentState;

        Managers::GraphicsManager* graphicsManager;

        // Singleton instance
        static Managers::StateManager* instance;

        // Private constructor to prevent instantiation
        StateManager();

    public:
        ~StateManager();

        // Get the singleton instance
        static Managers::StateManager* getInstance();

        void setCurrentState(const std::string stateName);
        std::string getCurrentStateName();
        States::State* getCurrentState();

        void addCurrentState(States::State* state);
        void removeState(const std::string stateName);

        States::State* getState(const std::string stateName);

        // Run the game loop
        void run();

        void changeState(std::string stateName);
    };
}
