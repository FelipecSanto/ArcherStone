#pragma once
#include "MenuState.h"

namespace States
{
    namespace Menus
    {
        class MenuOptionsState : public MenuState
        {
        private:
            GraphicsElements::Button* changeResolution;
            GraphicsElements::Button* changeSound;
            GraphicsElements::Button* changeLanguage;
            GraphicsElements::Button* changeControls;
            GraphicsElements::Button* returnButton;
            int opcao;

        public:
            MenuOptionsState();
            ~MenuOptionsState();

            void handleEvent(const sf::Event* event);
            void draw();
            void execute();
        };
    }
}