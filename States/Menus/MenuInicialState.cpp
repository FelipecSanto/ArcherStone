#include "MenuInicialState.h"
#include <iostream>

MenuInicialState::MenuInicialState():
MenuState("MenuInicialState"),
newGame(nullptr),
continueGame(nullptr),
loadGame(nullptr),
exit(nullptr)
{
    graphicsManager->loadTexture("../Assets/Backgrounds/MenuInicial.jpg", &texture);

    background.setTexture(&texture);
    background.setSize(graphicsManager->getWindowSize());
    background.setPosition(0, 0);

    graphicsManager->loadFont("../Fontes/Font.ttf", &font);

    title.setFont(font);
    title.setString("Platformer Game");
    title.setCharacterSize(50);
    title.setPosition(graphicsManager->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

    title.setFillColor(sf::Color::White);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(1);
    
    //Button(float x, float y, float width, float height, int characterSize, const sf::Font font, const std::string textStr);

    newGame = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 300, 150, 50, 10, "New Game");
    continueGame = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 375, 150, 50, 10, "Continue");
    loadGame = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 450, 150, 50, 10, "load Game");
    tutorial = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 525, 150, 50, 10, "Tutorial");
    ranking = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 600, 150, 50, 10, "Ranking");
    options = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 675, 150, 50, 10, "Options");
    exit = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, 750, 150, 50, 10, "Exit");
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

void MenuInicialState::handleEvent(const sf::Event* event)
{
    if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape) { 
        graphicsManager->getWindow()->close(); 
    }

    // Button hover events //////////////////////////////////////////////////////////


    // Play button
    if(newGame->isMouseOver())
    {
        newGame->setOutlineColor(sf::Color::White);
    }
    else
    {
        newGame->setOutlineColor(sf::Color::Blue);
    }

    // Continue button
    if(continueGame->isMouseOver())
    {
        continueGame->setOutlineColor(sf::Color::White);
    }
    else
    {
        continueGame->setOutlineColor(sf::Color::Blue);
    }

    // Load button
    if(loadGame->isMouseOver())
    {
        loadGame->setOutlineColor(sf::Color::White);
    }
    else
    {
        loadGame->setOutlineColor(sf::Color::Blue);
    }

    // Tutorial button
    if(tutorial->isMouseOver())
    {
        tutorial->setOutlineColor(sf::Color::White);
    }
    else
    {
        tutorial->setOutlineColor(sf::Color::Blue);
    }

    // Ranking button
    if(ranking->isMouseOver())
    {
        ranking->setOutlineColor(sf::Color::White);
    }
    else
    {
        ranking->setOutlineColor(sf::Color::Blue);
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


    // Button click events //////////////////////////////////////////////////////////


    // Play the game
    if(newGame->isClicked())
    {
        mediator->removeState("GameState");
        mediator->changeState("GameState");
    }

    // Continue the game
    if(continueGame->isClicked())
    {
        mediator->changeState("GameState");
    }

    // Load the game
    if(loadGame->isClicked())
    {
        // Load the game
    }

    // Show the tutorial
    if(tutorial->isClicked())
    {
        // Show the tutorial
    }

    // Show the ranking
    if(ranking->isClicked())
    {
        mediator->changeState("MenuRankingState");
    }

    // Show the options
    if(options->isClicked())
    {
        mediator->changeState("MenuOptionsState");
    }

    // Exit the game
    if(exit->isClicked())
    {
        graphicsManager->getWindow()->close();
    }
}

void MenuInicialState::draw()
{
    graphicsManager->setViewCenter(sf::Vector2f(graphicsManager->getWindow()->getSize().x / 2, graphicsManager->getWindow()->getSize().y / 2));

    graphicsManager->draw(background);
    graphicsManager->draw(title);

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
    draw();
}