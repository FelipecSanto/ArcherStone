#include "MenusObserver.h"
#include "../States/Menus/MenuState.h"

namespace Observers
{
    MenusObserver::MenusObserver(States::Menus::MenuState *menu):
    menuState(menu)
    {
    }

    MenusObserver::~MenusObserver()
    {
    }

    void MenusObserver::keyPressed(const sf::Keyboard::Key key)
    {
    }

    void MenusObserver::keyReleased(const sf::Keyboard::Key key)
    {
    }

    void MenusObserver::mousePressed(const sf::Mouse::Button mouseButton)
    {
        if(mouseButton == sf::Mouse::Left)
            menuState->mouseClick();
    }

    void MenusObserver::mouseReleased(const sf::Mouse::Button mouseButton)
    {
    }


}
