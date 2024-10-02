#include "GraphicsManager.h"
#include <iostream>


namespace Managers
{
    GraphicsManager* GraphicsManager::instance = nullptr;

    GraphicsManager::GraphicsManager():
    window(),
    viewport()
    {
        window.create(sf::VideoMode::getDesktopMode(), "SFML", sf::Style::Fullscreen);
        //window.create(sf::VideoMode(1000, 1000), "SFML");
        viewport.setSize(getWindowSize());
        viewport.setCenter(getWindowSize() / 2.f);
        setView(viewport);
        setFPS(60);
    }

    GraphicsManager::~GraphicsManager()
    {
    }

    GraphicsManager* GraphicsManager::getInstance()
    {
        if(instance == nullptr)
            instance = new GraphicsManager();
        return instance;
    }

    void GraphicsManager::clear()
    {
        window.clear();
    }

    void GraphicsManager::loadTexture(const std::string path, sf::Texture* texture)
    {
        if(!texture->loadFromFile(path))
        {
            std::cout << "ERROR::GraphicsManager::loadTexture" << std::endl;
        }
    }

    void GraphicsManager::loadFont(const std::string path, sf::Font* font)
    {
        if(!font->loadFromFile(path))
        {
            std::cout << "ERROR::GraphicsManager::loadFont" << std::endl;
        }
    }

    void GraphicsManager::setFPS(const int fps)
    {
        window.setFramerateLimit(fps);
    }

    void GraphicsManager::setView(const sf::View view)
    {
        window.setView(view);
    }

    void GraphicsManager::setViewCenter(const sf::Vector2f center)
    {
        viewport.setCenter(center);
        window.setView(viewport);
    }

    sf::Vector2f GraphicsManager::getViewCenter()
    {
        return viewport.getCenter();
    }

    sf::View GraphicsManager::getView()
    {
        return viewport;
    }

    void GraphicsManager::draw(const sf::Text t)
    {
        window.draw(t);
    }

    void GraphicsManager::draw(const sf::RectangleShape shape)
    {
        window.draw(shape);
    }

    void GraphicsManager::draw(const sf::Sprite sprite)
    {
        window.draw(sprite);
    }

    void GraphicsManager::display()
    {
        window.display();
    }

    sf::RenderWindow* GraphicsManager::getWindow()
    {
        return &window;
    }

    const sf::Vector2f GraphicsManager::getWindowSize()
    {
        return sf::Vector2f(window.getSize());
    }

    const bool GraphicsManager::isOpen()
    {
        return window.isOpen();
    }

    void GraphicsManager::CloseWindow()
    {
        window.close();
    }   
}
