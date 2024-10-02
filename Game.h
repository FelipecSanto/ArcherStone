#pragma once
#include <iostream>
#include "Managers/EventsManager.h"
#include "States/Menus/MenuInicialState.h"

class Game {
private:
    Managers::StateManager* stateMgr;
    Managers::EventsManager* eventsMgr;
    Managers::GraphicsManager* graphicsMgr;

public:
    Game();
    ~Game();

    void run();
};