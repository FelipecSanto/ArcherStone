#include "FaseStateObserver.h"

namespace Observers
{
    FaseStateObserver::FaseStateObserver(States::Fases::FaseState* fase):
    faseState(fase)
    {

    }

    FaseStateObserver::~FaseStateObserver()
    {
    }

    void FaseStateObserver::keyPressed(const sf::Keyboard::Key key)
    {
        if(key == sf::Keyboard::Escape)
        {
            stateMgr->changeState("MenuPauseState");
        }
    }

    void FaseStateObserver::keyReleased(const sf::Keyboard::Key key)
    {
    }

    void FaseStateObserver::mousePressed(const sf::Mouse::Button mouseButton)
    {
    }

    void FaseStateObserver::mouseReleased(const sf::Mouse::Button mouseButton)
    {
    }
}