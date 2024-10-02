#include "Game.h"

Game::Game():
stateMgr(Managers::StateManager::getInstance()),
eventsMgr(Managers::EventsManager::getInstance()),
graphicsMgr(Managers::GraphicsManager::getInstance())
{
    stateMgr->changeState("MenuInicialState");
    run();
}

Game::~Game()
{
}

void Game::run()
{
    while (graphicsMgr->isOpen() && !stateMgr->hasState())
    {
        // Clear the window
        graphicsMgr->clear();

        // Execute the current state
        stateMgr->run();

        // Execute the events manager
        eventsMgr->execute();

        // Display the window
        graphicsMgr->display();
    }
}
