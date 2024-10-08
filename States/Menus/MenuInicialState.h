#pragma once
#include "MenuState.h"

namespace States
{
    namespace Menus
    {
        class MenuInicialState : public MenuState
        {
        private:
            GraphicsElements::Button* newGame;
            GraphicsElements::Button* continueGame;
            GraphicsElements::Button* loadGame;
            GraphicsElements::Button* tutorial;
            GraphicsElements::Button* ranking;
            GraphicsElements::Button* options;
            GraphicsElements::Button* exit;

        public:
            MenuInicialState();
            ~MenuInicialState();

            void handleEvent(const sf::Event* event);
            void draw();
            void execute();
        };
    }
}