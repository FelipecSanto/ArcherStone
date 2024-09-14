#pragma once
#include "GraphicsManager.h"
#include <functional>
#include <vector>
#include <queue>
#include "../Observers/Observer.h"

namespace Managers 
{
    class EventsManager {
    private:
        std::vector<Observers::Observer*> lisObservers;

        std::queue<sf::Event> eventQueue;

        Managers::GraphicsManager* graphicsMgr;

        static EventsManager* instance;

        EventsManager();
    public:
        ~EventsManager();

        void addObserver(Observers::Observer* observer);

        static EventsManager* getInstance();

        void notifyKeyPressed(const sf::Keyboard::Key key);
        void notifyKeyRelease(const sf::Keyboard::Key key);

        void notifyMousePressed(const sf::Mouse::Button mouseButton);
        void notifyMouseReleased(const sf::Mouse::Button mouseButton);

        void execute();
    };  
}