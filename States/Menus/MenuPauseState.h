#pragma once
#include "MenuState.h"

class MenuPauseState : public MenuState
{
private:
    Button* resume;
    Button* save;
    Button* options;
    Button* exit;

public:
    MenuPauseState();
    ~MenuPauseState();

    void handleEvent(const sf::Event* event);
    void draw();
    void execute();
};