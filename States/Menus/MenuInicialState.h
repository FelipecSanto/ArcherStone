#pragma once
#include "MenuState.h"

class MenuInicialState : public MenuState
{
private:
    Button* newGame;
    Button* continueGame;
    Button* loadGame;
    Button* tutorial;
    Button* ranking;
    Button* options;
    Button* exit;

public:
    MenuInicialState();
    ~MenuInicialState();

    void handleEvent(const sf::Event* event);
    void draw();
    void execute();
};