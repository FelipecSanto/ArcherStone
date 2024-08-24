#pragma once
#include "GraphicsManager.h"
#include <map>

class FaseState;
class MenuInicialState;
class MenuPauseState;
class MenuOptionsState;
class MenuRankingState;
class State;

// Singleton
class StateManager
{
private:
    std::map<std::string, State*> statesMap;
    std::string currentState;

    GraphicsManager* graphicsManager;

    // Singleton instance
    static StateManager* instance;

    // Private constructor to prevent instantiation
    StateManager();

public:
    ~StateManager();

    // Get the singleton instance
    static StateManager* getInstance();

    void setCurrentState(const std::string stateName);
    std::string getCurrentStateName();
    State* getCurrentState();

    void addCurrentState(State* state);
    void removeState(const std::string stateName);

    State* getState(const std::string stateName);

    // Run the game loop
    void run();

    void changeState(std::string stateName);
};

