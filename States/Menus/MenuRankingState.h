#pragma once
#include "MenuState.h"

namespace States
{
    namespace Menus
    {
        class MenuRankingState : public MenuState
        {
        private:
            GraphicsElements::Button* returnButton;
            sf::Text score;
            sf::Text name;

        public:
            MenuRankingState();
            ~MenuRankingState();

            void handleEvent(const sf::Event* event);
            void draw();
            void execute();
        };
    }
}