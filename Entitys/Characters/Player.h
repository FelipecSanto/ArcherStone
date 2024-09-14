#pragma once
#include "Character.h"
#include "../../Observers/PlayerObserver.h"

#define VELOCIDADE_PULO 7.0f
#define GRAVIDADE 4.0f

namespace Entitys
{
    namespace Characters
    {
        namespace Players
        {
            class Player : public Character
            {
            private:
                int health;
                int maxHealth;
                int damage;
                int level;
                int experience;
                int experienceNext;
                int Points;

                float dtJump;
                sf::Clock jumpClock;
                bool jumping;

                Observers::PlayerObserver* plObserver;

            public:
                Player(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), sf::Vector2f si = sf::Vector2f(0.0, 0.0), Maps::QuadTree* q = nullptr);
                virtual ~Player();

                void setJumping(const bool jump);
                const bool getJumping();

                void loseHP(const int hp);
                void gainHP(const int hp);
                void loseExp(const int exp);
                void gainExp(const int exp);

                void loseMoney(const int money);
                void gainMoney(const int money);

                void updateStats();
                void updateLevel();
                void update();

                void move(std::string movement);
                void stop(std::string direction);

                void restartJumpClock();

                void executeJump();

                void execute();
            };
        }
    }
}