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
                graphicsManager->loadTexture("../Assets/Backgrounds/MenuOptions.jpg", &texture);
                background.setTexture(&texture);
                graphicsManager->loadFont("../Fontes/Font.ttf", &font);
                title.setFont(font);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

            background.setSize(graphicsManager->getWindowSize());
            background.setPosition(0, 0);

            title.setString("Options Menu");
            title.setCharacterSize(50);
            title.setPosition(graphicsManager->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

            title.setFillColor(sf::Color::White);
            title.setOutlineColor(sf::Color::Black);
            title.setOutlineThickness(1);
            
            //Button(float x, float y, float width, float height, int characterSize, const sf::Font font, const std::string textStr);

            changeResolution = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 400, 150, 50, 10, "Resolutions");
            changeSound = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 475, 150, 50, 10, "Sound");
            changeLanguage = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 550, 150, 50, 10, "Language");
            changeControls = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 625, 150, 50, 10, "Controls");
            returnButton = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 700, 150, 50, 10, "Return");
            
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

        void MenuOptionsState::handleEvent(const sf::Event* event)
        {
            if(event->type == sf::Event::KeyPressed)
            {
                if(event->key.code == sf::Keyboard::Up)
                {
                    if(opcao > 0)
                    {
                        opcao--;
                    }
                }
                else if(event->key.code == sf::Keyboard::Down)
                {
                    if(opcao < 3)
                    {
                        opcao++;
                    }
                }
                else if(event->key.code == sf::Keyboard::Return)
                {
                    switch(opcao)
                    {
                        case 0:
                            // Change resolution
                            break;
                        case 1:
                            // Change sound
                            break;
                        case 2:
                            // Change language
                            break;
                        case 3:
                            // Change controls
                            break;
                    }
                }
            }

            // Muda Resolucao
            if(changeResolution->isMouseOver())
            {
                changeResolution->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeResolution->setOutlineColor(sf::Color::Blue);
            }

            // Muda Som
            if(changeSound->isMouseOver())
            {
                changeSound->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeSound->setOutlineColor(sf::Color::Blue);
            }

            // Muda Idioma
            if(changeLanguage->isMouseOver())
            {
                changeLanguage->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeLanguage->setOutlineColor(sf::Color::Blue);
            }

            // Muda Controles
            if(changeControls->isMouseOver())
            {
                changeControls->setOutlineColor(sf::Color::White);
            }
            else
            {
                changeControls->setOutlineColor(sf::Color::Blue);
            }

            // Voltar
            if(returnButton->isMouseOver())
            {
                returnButton->setOutlineColor(sf::Color::White);
            }
            else
            {
                returnButton->setOutlineColor(sf::Color::Blue);
            }

            // Muda Resolucao
            if(changeResolution->isClicked())
            {
                // Change resolution
            }

            // Muda Som
            if(changeSound->isClicked())
            {
                // Change sound
            }

            // Muda Idioma
            if(changeLanguage->isClicked())
            {
                // Change language
            }

            // Muda Controles
            if(changeControls->isClicked())
            {
                // Change controls
            }

            // Voltar
            if(returnButton->isClicked())
            {
                stateManager->changeState("MenuInicialState");
            }
        }

        void MenuOptionsState::draw()
        {
            graphicsManager->setViewCenter(sf::Vector2f(graphicsManager->getWindow()->getSize().x / 2, graphicsManager->getWindow()->getSize().y / 2));

            graphicsManager->draw(background);
            graphicsManager->draw(title);
            
            changeResolution->render();
            changeSound->render();
            changeLanguage->render();
            changeControls->render();
            returnButton->render();
        }

        void MenuOptionsState::execute()
        {
            draw();
        }
    }
}