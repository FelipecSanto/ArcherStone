#include "MenuRankingState.h"

MenuRankingState::MenuRankingState():
MenuState("MenuRankingState"),
voltar(nullptr),
pontos()
{
    graphicsManager->loadTexture("../Assets/Backgrounds/MenuRanking.jpg", &texture);

    background.setTexture(&texture);
    background.setSize(graphicsManager->getWindowSize());
    background.setPosition(0, 0);

    graphicsManager->loadFont("../Fontes/Font.ttf", &font);

    title.setFont(font);
    title.setString("Ranking");
    title.setCharacterSize(50);
    title.setPosition(graphicsManager->getWindow()->getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

    title.setFillColor(sf::Color::White);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(1);

    pontos.setFont(font);
    pontos.setString("Pontos");
    pontos.setCharacterSize(30);
    pontos.setPosition((graphicsManager->getWindow()->getSize().x*3) / 4 - pontos.getGlobalBounds().width / 2,
                       graphicsManager->getWindow()->getSize().y / 4);
    pontos.setFillColor(sf::Color::White);
    pontos.setOutlineColor(sf::Color::Black);
    pontos.setOutlineThickness(1);


    name.setFont(font);
    name.setString("Nome");
    name.setCharacterSize(30);
    name.setPosition((graphicsManager->getWindow()->getSize().x) / 4 - name.getGlobalBounds().width / 2,
                       graphicsManager->getWindow()->getSize().y / 4);
    name.setFillColor(sf::Color::White);
    name.setOutlineColor(sf::Color::Black);
    name.setOutlineThickness(1);
    
    //Button(float x, float y, float width, float height, int characterSize, const sf::Font font, const std::string textStr);

    voltar = new Button(graphicsManager->getWindow()->getSize().x / 2 - 100, (graphicsManager->getWindow()->getSize().y*6)/8, 200, 100, 15, "Voltar");
}

MenuRankingState::~MenuRankingState()
{
    delete voltar;
    voltar = nullptr;
}

void MenuRankingState::handleEvent(const sf::Event* event)
{
    // Voltar button
    if(voltar->isMouseOver())
    {
        voltar->setOutlineColor(sf::Color::White);
    }
    else
    {
        voltar->setOutlineColor(sf::Color::Blue);
    }

    // Button events
    if(voltar->isClicked())
    {
        mediator->changeState("MenuInicialState");
    }
}

void MenuRankingState::draw()
{
    graphicsManager->setViewCenter(sf::Vector2f(graphicsManager->getWindow()->getSize().x / 2, graphicsManager->getWindow()->getSize().y / 2));

    graphicsManager->draw(background);
    graphicsManager->draw(title);
    graphicsManager->draw(pontos);
    graphicsManager->draw(name);

    voltar->render();
}

void MenuRankingState::execute()
{
    draw();
}
