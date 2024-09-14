#pragma once
#include "Observer.h"

namespace States
{
    namespace Fases
    {
        class FaseState;
    }
}

namespace Observers 
{
    class FaseStateObserver : public Observer {
    private:
        States::Fases::FaseState* faseState;

    public:
        FaseStateObserver(States::Fases::FaseState* fase = nullptr);
        ~FaseStateObserver();
        
        void keyPressed(const sf::Keyboard::Key key);
		void keyReleased(const sf::Keyboard::Key key);

        void mousePressed(const sf::Mouse::Button mouseButton);
		void mouseReleased(const sf::Mouse::Button mouseButton);
    };
}