#include "EventsManager.h"
#include <iostream>

namespace Managers
{

    EventsManager* EventsManager::instance = nullptr;

    EventsManager::EventsManager():
    lisObservers(),
    graphicsMgr(Managers::GraphicsManager::getInstance()),
    eventQueue()
    {
    }

    EventsManager::~EventsManager()
    {
        for (int i = 0; i < (int) lisObservers.size(); i++)
        {
            if(lisObservers[i]) {
                delete lisObservers[i];
                lisObservers[i] = nullptr;
            }
        }
        lisObservers.clear();
    }

    void EventsManager::addObserver(Observers::Observer *observer)
    {
        lisObservers.push_back(observer);
    }

    EventsManager* EventsManager::getInstance()
    {
        if(instance == nullptr)
            instance = new EventsManager();
        return instance;
    }

    void EventsManager::notifyKeyPressed(const sf::Keyboard::Key key)
    {
        for (int i = 0; i < (int) lisObservers.size(); i++)
            if (lisObservers[i]->getActivated())
                lisObservers[i]->keyPressed(key);
    }

    void EventsManager::notifyKeyRelease(const sf::Keyboard::Key key)
    {
        for (int i = 0; i < (int) lisObservers.size(); i++)
            if (lisObservers[i]->getActivated())
                lisObservers[i]->keyReleased(key);
    }

    void EventsManager::notifyMousePressed(const sf::Mouse::Button mouseButton)
    {
        for (int i = 0; i < (int) lisObservers.size(); i++)
            if (lisObservers[i]->getActivated())
                lisObservers[i]->mousePressed(mouseButton);
    }

    void EventsManager::notifyMouseReleased(const sf::Mouse::Button mouseButton)
    {
        for (int i = 0; i < (int) lisObservers.size(); i++)
            if (lisObservers[i]->getActivated())
                lisObservers[i]->mouseReleased(mouseButton);
    }

    void EventsManager::execute()
    {
        sf::Event event;

        /*if(!eventQueue.empty())
            eventQueue.pop();

        graphicsMgr->getWindow()->pollEvent(event);
        eventQueue.push(event);*/

        while (graphicsMgr->getWindow()->pollEvent(event))
        {
            /*event = eventQueue.front();
            if(!eventQueue.empty())
                eventQueue.pop();*/

            // Teclado
            if (event.type == sf::Event::KeyPressed)
                notifyKeyPressed(event.key.code);
            else if (event.type == sf::Event::KeyReleased)
                notifyKeyRelease(event.key.code);
            else if (event.type == sf::Event::MouseButtonPressed)
                notifyMousePressed(event.mouseButton.button);
            else if(event.type == sf::Event::MouseButtonReleased)
                notifyMouseReleased(event.mouseButton.button);

            // Exit
            else if (event.type == sf::Event::Closed) {
                graphicsMgr->CloseWindow();
            }
            
            //graphicsMgr->getWindow()->pollEvent(event);
            //eventQueue.push(event);
        }
    }
}