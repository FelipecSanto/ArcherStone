#include <iostream>
#include <stack>
#include "Managers/StateManager.h"
#include "States/Menus/MenuInicialState.h"

int main(){    
    Managers::StateManager* stateManager = Managers::StateManager::getInstance();
    stateManager->addCurrentState(static_cast<States::State*>(new States::Menus::MenuInicialState()));
    stateManager->run();

    return 0;
}

//MenuOpcoesState.h MenuOpcoesState.cpp MenuCreditosState.h MenuCreditosState.cpp MenuTuturiolState.h MenuTuturiolState.cpp MenuGameOverState.h MenuGameOverState.cpp MenuWonState.h MenuWonState.cpp