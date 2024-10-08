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
            graphicsManager->loadTexture("../Assets/Backgrounds/MenuPause.jpg", &texture);

            background.setTexture(&texture);
            background.setSize(graphicsManager->getWindowSize());
            background.setPosition(0, 0);

            graphicsManager->loadFont("../Fontes/Font.ttf", &font);

            title.setFont(font);
            title.setString("Pause Menu");
            title.setCharacterSize(50);
            title.setPosition(graphicsManager->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

            title.setFillColor(sf::Color::White);
            title.setOutlineColor(sf::Color::Black);
            title.setOutlineThickness(1);

            //Button(float x, float y, float width, float height, int characterSize, const sf::Font font, const std::string textStr);

            returnButton = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 200, 150, 50, 10, "Return");
            save = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 300, 150, 50, 10, "Save");
            options = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 400, 150, 50, 10, "Options");
            exit = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 500, 150, 50, 10, "Exit");
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

        void MenuPauseState::handleEvent(const sf::Event* event)
        {
            // Resume button
            if(returnButton->isMouseOver())
            {
                returnButton->setOutlineColor(sf::Color::White);
            }
            else
            {
                returnButton->setOutlineColor(sf::Color::Blue);
            }

            // Save button
            if(save->isMouseOver())
            {
                save->setOutlineColor(sf::Color::White);
            }
            else
            {
                save->setOutlineColor(sf::Color::Blue);
            }

            // Options button
            if(options->isMouseOver())
            {
                options->setOutlineColor(sf::Color::White);
            }
            else
            {
                options->setOutlineColor(sf::Color::Blue);
            }

            // Exit button
            if(exit->isMouseOver())
            {
                exit->setOutlineColor(sf::Color::White);
            }
            else
            {
                exit->setOutlineColor(sf::Color::Blue);
            }

            // Resume the game
            if(returnButton->isClicked())
            {
                stateManager->changeState("GameState");
            }

            // Save the game   
            if(save->isClicked())
            {
                // Save the game
            }

            // Options
            if(options->isClicked())
            {
                // Go to the options menu
            }

            // Exit the game
            if(exit->isClicked())
            {
                stateManager->changeState("MenuInicialState");
            }
        }

        void MenuPauseState::draw()
        {
            graphicsManager->setViewCenter(sf::Vector2f(graphicsManager->getWindow()->getSize().x / 2, graphicsManager->getWindow()->getSize().y / 2));


            graphicsManager->draw(background);
            graphicsManager->draw(title);

            returnButton->render();
            save->render();
            options->render();
            exit->render();
        }

        void MenuPauseState::execute()
        {
            draw();
        }
    }
}