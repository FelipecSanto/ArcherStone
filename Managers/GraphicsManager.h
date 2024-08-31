#pragma once
#include <SFML/Graphics.hpp>

namespace Managers
{
    class GraphicsManager
    {
    private:
        sf::RenderWindow window;
        sf::View viewport;

        static GraphicsManager* instance;

        GraphicsManager();

    public:
        ~GraphicsManager();

        static GraphicsManager* getInstance();

        void clear();

        void loadTexture(const std::string path, sf::Texture* texture);
        void loadFont(const std::string path, sf::Font* font);
        void setFPS(const int fps);

        void setView(const sf::View view);
        void setViewCenter(const sf::Vector2f center);

        sf::Vector2f getViewCenter();
        sf::View getView();

        void draw(const sf::Text t);
        void draw(const sf::RectangleShape shape);
        void draw(const sf::Sprite sprite);

        void display();

        sf::RenderWindow* getWindow();
        const sf::Vector2f getWindowSize();

        const bool isOpen();

        void CloseWindow();
    };
}