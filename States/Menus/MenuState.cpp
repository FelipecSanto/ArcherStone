#include "MenuState.h"
#include "../../Managers/EventsManager.h"

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
    }
}