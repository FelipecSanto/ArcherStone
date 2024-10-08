#pragma once
#include "MenuState.h"

namespace States
{
    namespace Menus
    {
        class MenuPauseState : public MenuState
        {
        private:
            GraphicsElements::Button* returnButton;
            GraphicsElements::Button* save;
            GraphicsElements::Button* options;
            GraphicsElements::Button* exit;

        public:
            MenuPauseState();
            ~MenuPauseState();

            void handleEvent(const sf::Event* event);
            void draw();
            void execute();
        };
    }
}