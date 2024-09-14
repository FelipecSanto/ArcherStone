#include "Button.h"
#include <iostream>

namespace GraphicsElements
{
    Button::Button(float x, float y, float width, float height, int characterSize, std::string textStr):
    shape(),
    text(),
    graphicsMgr(Managers::GraphicsManager::getInstance())
    {
        shape.setPosition(x, y);
        shape.setSize({width, height});
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color::Blue);
        shape.setFillColor(sf::Color::Blue);

        graphicsMgr->loadFont("../Fontes/Font.ttf", &font);

        text.setFont(font);
        text.setString(textStr);
        text.setCharacterSize(characterSize);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + width/2 - text.getGlobalBounds().width/2, y + height/2 - text.getGlobalBounds().height/2);
        text.setOutlineColor(sf::Color::Black);
        text.setOutlineThickness(1);
    }

    Button::~Button()
    {
    }

    void Button::render()
    {
        graphicsMgr->draw(shape);
        graphicsMgr->draw(text);
    }

    void Button::setText(const std::string textStr)
    {
        text.setString(textStr);
    }

    sf::Text Button::getText()
    {
        return text;
    }

    void Button::setFillColor(const sf::Color color)
    {
        shape.setFillColor(color);
    }

    void Button::setOutlineColor(const sf::Color color)
    {
        shape.setOutlineColor(color);
    }

    const bool Button::isMouseOver()
    {
        int mouseX = sf::Mouse::getPosition(*graphicsMgr->getWindow()).x;  
        int mouseY = sf::Mouse::getPosition(*graphicsMgr->getWindow()).y;

        sf::FloatRect buttonBounds = shape.getGlobalBounds();

        return buttonBounds.contains(mouseX, mouseY);
    }

    const bool Button::isClicked()
    {
        return sf::Mouse::isButtonPressed(sf::Mouse::Left) && isMouseOver();
    }
}
