#include "MenuInicialState.h"
#include <iostream>

namespace States
{
    namespace Menus
    {
        MenuInicialState::MenuInicialState():
        MenuState("MenuInicialState"),
        newGame(nullptr),
        continueGame(nullptr),
        loadGame(nullptr),
        exit(nullptr)
        {
            graphicsMgr->loadTexture("../Assets/Backgrounds/MenuInicial.jpg", &texture);

            background.setTexture(&texture);
            background.setSize(graphicsMgr->getWindowSize());
            background.setPosition(0, 0);

            graphicsMgr->loadFont("../Fontes/Font.ttf", &font);

            title.setFont(font);
            title.setString("Archer Stone");
            title.setCharacterSize(50);
            title.setPosition(graphicsMgr->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

            title.setFillColor(sf::Color::White);
            title.setOutlineColor(sf::Color::Black);
            title.setOutlineThickness(1);
            
            //Button(float x, float y, float width, float height, int characterSize, const std::string textStr);

            newGame = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 300, 150, 50, 10, "New Game");
            continueGame = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 375, 150, 50, 10, "Continue");
            loadGame = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 450, 150, 50, 10, "Load Game");
            tutorial = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 525, 150, 50, 10, "Tutorial");
            ranking = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 600, 150, 50, 10, "Ranking");
            options = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 675, 150, 50, 10, "Options");
            exit = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 750, 150, 50, 10, "Exit");
        }
        MenuInicialState::~MenuInicialState()
        {
            delete newGame;
            delete continueGame;
            delete loadGame;
            delete tutorial;
            delete ranking;
            delete options;
            delete exit;
            newGame = nullptr;
            continueGame = nullptr;
            loadGame = nullptr;
            tutorial = nullptr;
            ranking = nullptr;
            options = nullptr;
            exit = nullptr;
        }

        void MenuInicialState::mouseClick()
        {
            if(newGame->mouseOver())
            {
                stateMgr->removeState("FaseState");
                stateMgr->changeState("FaseState");
            }

            if(continueGame->mouseOver())
            {
                stateMgr->changeState("FaseState");
            }

            if(loadGame->mouseOver())
            {
                // Load the game
            }

            if(tutorial->mouseOver())
            {
                // Show the tutorial
            }

            if(ranking->mouseOver())
            {
                stateMgr->changeState("MenuRankingState");
            }

            if(options->mouseOver())
            {
                stateMgr->changeState("MenuOptionsState");
            }

            // Exit the game
            if(exit->mouseOver())
            {
                graphicsMgr->getWindow()->close();
            }
        }

        void MenuInicialState::mouseOver()
        {
            // Play button
            if(newGame->mouseOver())
            {
                newGame->setOutlineColor(sf::Color::White);
            }
            else
            {
                newGame->setOutlineColor(sf::Color::Blue);
            }

            // Continue button
            if(continueGame->mouseOver())
            {
                continueGame->setOutlineColor(sf::Color::White);
            }
            else
            {
                continueGame->setOutlineColor(sf::Color::Blue);
            }

            // Load button
            if(loadGame->mouseOver())
            {
                loadGame->setOutlineColor(sf::Color::White);
            }
            else
            {
                loadGame->setOutlineColor(sf::Color::Blue);
            }

            // Tutorial button
            if(tutorial->mouseOver())
            {
                tutorial->setOutlineColor(sf::Color::White);
            }
            else
            {
                tutorial->setOutlineColor(sf::Color::Blue);
            }

            // Ranking button
            if(ranking->mouseOver())
            {
                ranking->setOutlineColor(sf::Color::White);
            }
            else
            {
                ranking->setOutlineColor(sf::Color::Blue);
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

        void MenuInicialState::draw()
        {
            graphicsMgr->setViewCenter(sf::Vector2f(graphicsMgr->getWindow()->getSize().x / 2, graphicsMgr->getWindow()->getSize().y / 2));

            graphicsMgr->draw(background);
            graphicsMgr->draw(title);

            newGame->render();
            continueGame->render();
            loadGame->render();
            tutorial->render();
            ranking->render();
            options->render();
            exit->render();
        }

        void MenuInicialState::execute()
        {
            mouseOver();
            draw();
        }
    }
}