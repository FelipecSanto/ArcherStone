#include <iostream>
#include <stack>
#include "States/Menus/MenuInicialState.h"

int main(){    
    StateManager* stateManager = StateManager::getInstance();
    stateManager->addCurrentState(static_cast<State*>(new MenuInicialState()));
    stateManager->run();

    return 0;
}

//MenuOpcoesState.h MenuOpcoesState.cpp MenuCreditosState.h MenuCreditosState.cpp MenuTuturiolState.h MenuTuturiolState.cpp MenuGameOverState.h MenuGameOverState.cpp MenuWonState.h MenuWonState.cpp