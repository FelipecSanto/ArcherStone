#pragma once
#include "../State.h"
#include "../../GraphicsElements/Button.h"
#include "../../Managers/StateManager.h"

namespace States
{
    namespace Menus
    {
        class MenuState : public State
        {
        protected:
            sf::Text title;
            sf::RectangleShape background;
            sf::Texture texture;
            sf::Font font;

        public:
            MenuState(std::string nam = "MenuState");
            ~MenuState();

            void handleEvent(const sf::Event* event) = 0;
            void draw() = 0;
            void execute() = 0;
        };
    }
}