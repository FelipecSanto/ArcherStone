#include "StateManager.h"
#include "../States/Menus/MenuInicialState.h"
#include "../States/Fases/FaseState.h"
#include "../States/Menus/MenuPauseState.h"
#include "../States/Menus/MenuOptionsState.h"
#include "../States/Menus/MenuRankingState.h"
#include <iostream>

namespace Managers
{
    StateManager* StateManager::instance = nullptr;

    StateManager::StateManager():
    statesMap(),
    currentState(""),
    graphicsManager(GraphicsManager::getInstance())
    {
    }

    StateManager::~StateManager()
    {
        // Deallocate the statesMap
        for (auto pair : statesMap)
        {
            delete pair.second;
            pair.second = nullptr;
        }
        statesMap.clear();
    }

    StateManager* StateManager::getInstance()
    {
        if (instance == nullptr)
        {
            instance = new StateManager();
        }
        return instance;
    }

    void StateManager::setCurrentState(const std::string stateName)
    {
        currentState = stateName;
    }

    std::string StateManager::getCurrentStateName()
    {
        return currentState;
    }

    States::State *StateManager::getCurrentState()
    {
        return statesMap[currentState];
    }

    // Push a new state onto the stack
    void StateManager::addCurrentState(States::State* state)
    {
        currentState = state->getName();
        statesMap[state->getName()] = state;
    }

    // Remove a state from the statesMap
    void StateManager::removeState(const std::string stateName)
    {
        auto it = statesMap.find(stateName);
        if (it != statesMap.end())
        {
            delete it->second;
            statesMap.erase(it);
        }
    }

    States::State *StateManager::getState(const std::string stateName)
    {
        return statesMap[stateName];
    }

    // Run the game loop
    void StateManager::run()
    {
        while (graphicsManager->isOpen() && !statesMap.empty())
        {
            // Handle events
            sf::Event event;
            while (graphicsManager->getWindow()->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    graphicsManager->CloseWindow();

                statesMap[currentState]->handleEvent(&event);
            }

            // Clear the window
            graphicsManager->clear();

            // Execute the current state
            statesMap[currentState]->execute();

            // Display the window
            graphicsManager->display();
        }
    }

    void StateManager::changeState(std::string stateName)
    {
        // Check if the state exists in the statesMap
        if (statesMap.find(stateName) != statesMap.end())
        {
            // Set the current state to the new state
            currentState = stateName;
        }
        else
        {
            // Add the new state to the statesMap
            if(stateName == "MenuInicialState")
            {
                addCurrentState(static_cast<States::State*>(new States::Menus::MenuInicialState()));
            }
            else if(stateName == "GameState")
            {
                addCurrentState(static_cast<States::State*>(new States::Fases::FaseState("../Mapa/tiled/Fase1_1.tmj")));
            }
            else if(stateName == "MenuPauseState")
            {
                addCurrentState(static_cast<States::State*>(new States::Menus::MenuPauseState()));
            }
            else if(stateName == "MenuOptionsState")
            {
                addCurrentState(static_cast<States::State*>(new States::Menus::MenuOptionsState()));
            }
            else if(stateName == "MenuRankingState")
            {
                addCurrentState(static_cast<States::State*>(new States::Menus::MenuRankingState()));
            }
        }
    }
}