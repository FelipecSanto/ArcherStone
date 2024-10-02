#include "MenuPauseState.h"
#include <iostream>

namespace States
{
    namespace Menus
    {
        MenuPauseState::MenuPauseState():
        MenuState("MenuPauseState"),
        returnButton(nullptr),
        exit(nullptr)
        {
            graphicsMgr->loadTexture("../Assets/Backgrounds/MenuPause.jpg", &texture);

            background.setTexture(&texture);
            background.setSize(graphicsMgr->getWindowSize());
            background.setPosition(0, 0);

            graphicsMgr->loadFont("../Fontes/Font.ttf", &font);

            title.setFont(font);
            title.setString("Pause Menu");
            title.setCharacterSize(50);
            title.setPosition(graphicsMgr->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

            title.setFillColor(sf::Color::White);
            title.setOutlineColor(sf::Color::Black);
            title.setOutlineThickness(1);

            //Button(float x, float y, float width, float height, int characterSize, const sf::Font font, const std::string textStr);

            returnButton = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 200, 150, 50, 10, "Return");
            save = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 300, 150, 50, 10, "Save");
            options = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 400, 150, 50, 10, "Options");
            exit = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 500, 150, 50, 10, "Exit");
        }

        MenuPauseState::~MenuPauseState()
        {
            delete returnButton;
            delete save;
            delete options;
            delete exit;
            returnButton = nullptr;
            save = nullptr;
            options = nullptr;
            exit = nullptr;
        }

        void MenuPauseState::mouseClick()
        {
            if(returnButton->mouseOver())
            {
                stateMgr->changeState("FaseState");
            }

            if(save->mouseOver())
            {
                // Save the game
            }

            if(options->mouseOver())
            {
                // Go to the options menu
            }

            if(exit->mouseOver())
            {
                stateMgr->changeState("MenuInicialState");
            }
        }

        void MenuPauseState::mouseOver()
        {
            // Resume button
            if(returnButton->mouseOver())
            {
                returnButton->setOutlineColor(sf::Color::White);
            }
            else
            {
                returnButton->setOutlineColor(sf::Color::Blue);
            }

            // Save button
            if(save->mouseOver())
            {
                save->setOutlineColor(sf::Color::White);
            }
            else
            {
                save->setOutlineColor(sf::Color::Blue);
            }

            // Options button
            if(options->mouseOver())
            {
                options->setOutlineColor(sf::Color::White);
            }
            else
            {
                options->setOutlineColor(sf::Color::Blue);
            }

            // Exit button
            if(exit->mouseOver())
            {
                exit->setOutlineColor(sf::Color::White);
            }
            else
            {
                exit->setOutlineColor(sf::Color::Blue);
            }
        }

        void MenuPauseState::draw()
        {
            graphicsMgr->setViewCenter(sf::Vector2f(graphicsMgr->getWindow()->getSize().x / 2, graphicsMgr->getWindow()->getSize().y / 2));


            graphicsMgr->draw(background);
            graphicsMgr->draw(title);

            returnButton->render();
            save->render();
            options->render();
            exit->render();
        }

        void MenuPauseState::execute()
        {
            mouseOver();
            draw();
        }
    }
}