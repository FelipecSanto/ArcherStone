#include "GameState.h"

GameState::GameState(std::string name):
State(name),
corpo(sf::RectangleShape()),
fundo(sf::Texture()),
collisionMan(CollisionManager::getInstance())
{
}

GameState::~GameState()
{
}

void GameState::handleEvent(const sf::Event* event)
{
    if(event->type == sf::Event::KeyPressed)
    {
        if(event->key.code == sf::Keyboard::Escape)
        {
            mediator->changeState("MenuPauseState");
        }
    }
}