#pragma once
#include "../State.h"
#include "../../Managers/CollisionManager.h"

class GameState : public State
{
protected:
    sf::RectangleShape corpo;
    sf::Texture fundo;

    CollisionManager* collisionMan;

public:
    GameState(std::string name = "GameState");
    ~GameState();

    void handleEvent(const sf::Event* event);
    virtual void draw() = 0;
    virtual void execute() = 0;
};


