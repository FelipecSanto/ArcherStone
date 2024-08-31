#include "MenuState.h"

namespace States
{
    namespace Menus
    {
        MenuState::MenuState(std::string nam):
        State(nam),
        title(),
        background(),
        texture(),
        font()
        {
        }

        MenuState::~MenuState()
        {
        }
    }
}