#include "MenuOptionsState.h"
#include <iostream>

namespace States
{
    namespace Menus
    {
        MenuOptionsState::MenuOptionsState() :
            MenuState("MenuOptionsState"),
            changeResolution(nullptr),
            changeSound(nullptr),
            changeLanguage(nullptr),
            changeControls(nullptr),
            returnButton(nullptr),
            opcao(0)
        {
            try
            {
                graphicsMgr->loadTexture("../Assets/Backgrounds/MenuOptions.jpg", &texture);
                background.setTexture(&texture);
                graphicsMgr->loadFont("../Fontes/Font.ttf", &font);
                title.setFont(font);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

            background.setSize(graphicsMgr->getWindowSize());
            background.setPosition(0, 0);

            title.setString("Options Menu");
            title.setCharacterSize(50);
            title.setPosition(graphicsMgr->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

            title.setFillColor(sf::Color::White);
            title.setOutlineColor(sf::Color::Black);
            title.setOutlineThickness(1);
            
            //Button(float x, float y, float width, float height, int characterSize, const sf::Font font, const std::string textStr);

            changeResolution = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 400, 150, 50, 10, "Resolutions");
            changeSound = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 475, 150, 50, 10, "Sound");
            changeLanguage = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 550, 150, 50, 10, "Language");
            changeControls = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 625, 150, 50, 10, "Controls");
            returnButton = new GraphicsElements::Button(graphicsMgr->getWindow()->getSize().x / 2 - 100, 700, 150, 50, 10, "Return");
            
            opcao = 0;
        }

        MenuOptionsState::~MenuOptionsState()
        {
            delete changeResolution;
            delete changeSound;
            delete changeLanguage;
            delete changeControls;
            delete returnButton;
            changeResolution = nullptr;
            changeSound = nullptr;
            changeLanguage = nullptr;
            changeControls = nullptr;
            returnButton = nullptr;
        }

        void MenuOptionsState::mouseClick()
        {
            if(changeResolution->mouseOver())
            {
                // Change resolution
            }

            if(changeSound->mouseOver())
            {
                // Change sound
            }

            if(changeLanguage->mouseOver())
            {
                // Change language
            }

            if(changeControls->mouseOver())
            {
                // Change controls
            }

            if(returnButton->mouseOver())
            {
                stateMgr->changeState("MenuInicialState");
            }
        }

        void MenuOptionsState::mouseOver()
        {
            // Muda Resolucao
            if(changeResolution->mouseOver())
            {
                changeResolution->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeResolution->setOutlineColor(sf::Color::Blue);
            }

            // Muda Som
            if(changeSound->mouseOver())
            {
                changeSound->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeSound->setOutlineColor(sf::Color::Blue);
            }

            // Muda Idioma
            if(changeLanguage->mouseOver())
            {
                changeLanguage->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeLanguage->setOutlineColor(sf::Color::Blue);
            }

            // Muda Controles
            if(changeControls->mouseOver())
            {
                changeControls->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeControls->setOutlineColor(sf::Color::Blue);
            }

            // Voltar
            if(returnButton->mouseOver())
            {
                returnButton->setOutlineColor(sf::Color::White);
            }
            else
            {
                returnButton->setOutlineColor(sf::Color::Blue);
            }
        }

        void MenuOptionsState::draw()
        {
            graphicsMgr->setViewCenter(sf::Vector2f(graphicsMgr->getWindow()->getSize().x / 2, graphicsMgr->getWindow()->getSize().y / 2));

            graphicsMgr->draw(background);
            graphicsMgr->draw(title);
            
            changeResolution->render();
            changeSound->render();
            changeLanguage->render();
            changeControls->render();
            returnButton->render();
        }

        void MenuOptionsState::execute()
        {
            mouseOver();
            draw();
        }
    }
}