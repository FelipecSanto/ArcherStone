#pragma once
#include "../State.h"
#include "../../GraphicsElements/Button.h"
#include "../../Observers/MenusObserver.h"

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

            Observers::MenusObserver* observer;

        public:
            MenuState(std::string nam = "MenuState");
            virtual ~MenuState();

            virtual void mouseMenuInteractions() = 0;
            virtual void draw() = 0;
            virtual void execute() = 0;
        };
    }
}