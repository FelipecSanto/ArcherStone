#pragma once
#include "../Managers/StateManager.h"

namespace Observers
{
    class Observer {
    protected:
		Managers::StateManager* stateMgr;

	private:
		bool activated;

	public:
		Observer();
		~Observer();

		void setActivated(const bool active);
		const bool getActivated() const;

        virtual void keyPressed(const sf::Keyboard::Key key) = 0;
		virtual void keyReleased(const sf::Keyboard::Key key) = 0;

        virtual void mousePressed(const sf::Mouse::Button mouseButton) = 0;
		virtual void mouseReleased(const sf::Mouse::Button mouseButton) = 0;
    };
}