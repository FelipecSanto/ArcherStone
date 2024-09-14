#pragma once

#include "Observer.h"

namespace Entitys 
{
    namespace Characters
    {
        namespace Players
        {
            class Player;
        }
    }
}


namespace Observers 
{
    class PlayerObserver : public Observer {
    private:
        Entitys::Characters::Players::Player* player;

    public:
        PlayerObserver(Entitys::Characters::Players::Player* pl = nullptr);
        ~PlayerObserver();

        void keyPressed(const sf::Keyboard::Key key);
		void keyReleased(const sf::Keyboard::Key key);

        void mousePressed(const sf::Mouse::Button mouseButton);
		void mouseReleased(const sf::Mouse::Button mouseButton);
    };
}