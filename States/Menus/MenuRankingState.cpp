#include "MenuRankingState.h"

namespace States
{
    namespace Menus
    {
        MenuRankingState::MenuRankingState():
        MenuState("MenuRankingState"),
        returnButton(nullptr),
        score()
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

            score.setFont(font);
            score.setString("Score");
            score.setCharacterSize(30);
            score.setPosition((graphicsManager->getWindow()->getSize().x*3) / 4 - score.getGlobalBounds().width / 2,
                            graphicsManager->getWindow()->getSize().y / 4);
            score.setFillColor(sf::Color::White);
            score.setOutlineColor(sf::Color::Black);
            score.setOutlineThickness(1);


            name.setFont(font);
            name.setString("Name");
            name.setCharacterSize(30);
            name.setPosition((graphicsManager->getWindow()->getSize().x) / 4 - name.getGlobalBounds().width / 2,
                            graphicsManager->getWindow()->getSize().y / 4);
            name.setFillColor(sf::Color::White);
            name.setOutlineColor(sf::Color::Black);
            name.setOutlineThickness(1);
            
            //Button(float x, float y, float width, float height, int characterSize, const sf::Font font, const std::string textStr);

            returnButton = new GraphicsElements::Button(graphicsManager->getWindow()->getSize().x / 2 - 100, (graphicsManager->getWindow()->getSize().y*6)/8, 200, 100, 15, "Return");
        }

        MenuRankingState::~MenuRankingState()
        {
            delete returnButton;
            returnButton = nullptr;
        }

        void MenuRankingState::handleEvent(const sf::Event* event)
        {
            // Voltar button
            if(returnButton->isMouseOver())
            {
                returnButton->setOutlineColor(sf::Color::White);
            }
            else
            {
                returnButton->setOutlineColor(sf::Color::Blue);
            }

            // Button events
            if(returnButton->isClicked())
            {
                stateManager->changeState("MenuInicialState");
            }
        }

        void MenuRankingState::draw()
        {
            graphicsManager->setViewCenter(sf::Vector2f(graphicsManager->getWindow()->getSize().x / 2, graphicsManager->getWindow()->getSize().y / 2));

            graphicsManager->draw(background);
            graphicsManager->draw(title);
            graphicsManager->draw(score);
            graphicsManager->draw(name);

            returnButton->render();
        }

        void MenuRankingState::execute()
        {
            draw();
        }
    }
}
