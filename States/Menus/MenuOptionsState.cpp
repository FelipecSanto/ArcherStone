#include "MenuOptionsState.h"
#include <iostream>

MenuOptionsState::MenuOptionsState() :
    MenuState("MenuOptionsState"),
    mudaResolucao(nullptr),
    mudaSom(nullptr),
    mudaIdioma(nullptr),
    mudaControles(nullptr),
    voltar(nullptr),
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

    mudaResolucao = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 400, 150, 50, 10, "Resolucao");
    mudaSom = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 475, 150, 50, 10, "Som");
    mudaIdioma = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 550, 150, 50, 10, "Idioma");
    mudaControles = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 625, 150, 50, 10, "Controles");
    voltar = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 700, 150, 50, 10, "Voltar");
    
    opcao = 0;
}

MenuOptionsState::~MenuOptionsState()
{
    delete mudaResolucao;
    delete mudaSom;
    delete mudaIdioma;
    delete mudaControles;
    delete voltar;
    mudaResolucao = nullptr;
    mudaSom = nullptr;
    mudaIdioma = nullptr;
    mudaControles = nullptr;
    voltar = nullptr;
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
    if(mudaResolucao->isMouseOver())
    {
        mudaResolucao->setOutlineColor(sf::Color::White);
    }
    else
    {
        mudaResolucao->setOutlineColor(sf::Color::Blue);
    }

    // Muda Som
    if(mudaSom->isMouseOver())
    {
        mudaSom->setOutlineColor(sf::Color::White);
    }
    else
    {
        mudaSom->setOutlineColor(sf::Color::Blue);
    }

    // Muda Idioma
    if(mudaIdioma->isMouseOver())
    {
        mudaIdioma->setOutlineColor(sf::Color::White);
    }
    else
    {
        mudaIdioma->setOutlineColor(sf::Color::Blue);
    }

    // Muda Controles
    if(mudaControles->isMouseOver())
    {
        mudaControles->setOutlineColor(sf::Color::White);
    }
    else
    {
        mudaControles->setOutlineColor(sf::Color::Blue);
    }

    // Voltar
    if(voltar->isMouseOver())
    {
        voltar->setOutlineColor(sf::Color::White);
    }
    else
    {
        voltar->setOutlineColor(sf::Color::Blue);
    }

    // Muda Resolucao
    if(mudaResolucao->isClicked())
    {
        // Change resolution
    }

    // Muda Som
    if(mudaSom->isClicked())
    {
        // Change sound
    }

    // Muda Idioma
    if(mudaIdioma->isClicked())
    {
        // Change language
    }

    // Muda Controles
    if(mudaControles->isClicked())
    {
        // Change controls
    }

    // Voltar
    if(voltar->isClicked())
    {
        mediator->changeState("MenuInicialState");
    }
}

void MenuOptionsState::draw()
{
    graphicsManager->setViewCenter(sf::Vector2f(graphicsManager->getWindow()->getSize().x / 2, graphicsManager->getWindow()->getSize().y / 2));

    graphicsManager->draw(background);
    graphicsManager->draw(title);
    
    mudaResolucao->render();
    mudaSom->render();
    mudaIdioma->render();
    mudaControles->render();
    voltar->render();
}

void MenuOptionsState::execute()
{
    draw();
}