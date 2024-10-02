#include "MenuState.h"
#include <iostream>

namespace States
{
    namespace Menus
    {
        MenuState::MenuState(std::string nam):
        State(nam),
        title(),
        background(),
        texture(),
        font(),
        observer(new Observers::MenusObserver(this))
        {
            eventsMgr->addObserver(observer);
        }

        MenuState::~MenuState()
        {
        }

        void MenuState::activateObserver()
        {
            observer->setActivated(true);
        }

        void MenuState::deactivateObserver()
        {
            observer->setActivated(false);
        }
    }
}