#pragma once
#include "MenuState.h"

class MenuOptionsState : public MenuState
{
private:
    Button* mudaResolucao;
    Button* mudaSom;
    Button* mudaIdioma;
    Button* mudaControles;
    Button* voltar;
    int opcao;

public:
    MenuOptionsState();
    ~MenuOptionsState();

    void handleEvent(const sf::Event* event);
    void draw();
    void execute();
};