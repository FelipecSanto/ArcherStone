#include "GameState.h"

namespace States
{
    namespace Fases
    {
        GameState::GameState(std::string name):
        State(name),
        corpo(),
        fundo(),
        collisionMan(Managers::CollisionManager::getInstance())
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
                    stateManager->changeState("MenuPauseState");
                }
            }
        }
    }
}