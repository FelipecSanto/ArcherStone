#pragma once
#include "Observer.h"

namespace States
{
    namespace Menus
    {
        class MenuState;
    }
}

namespace Observers 
{
    class MenusObserver : public Observer {
    private:
        States::Menus::MenuState* menuState;

    public:
        MenusObserver(States::Menus::MenuState* menu);
        ~MenusObserver();

        void keyPressed(const sf::Keyboard::Key key);
		void keyReleased(const sf::Keyboard::Key key);

        void mousePressed(const sf::Mouse::Button mouseButton);
		void mouseReleased(const sf::Mouse::Button mouseButton);
    };
}