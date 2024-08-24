#pragma once
#include "MenuState.h"

class MenuRankingState : public MenuState
{
private:
    Button* voltar;
    sf::Text pontos;
    sf::Text name;

public:
    MenuRankingState();
    ~MenuRankingState();

    void handleEvent(const sf::Event* event);
    void draw();
    void execute();
};