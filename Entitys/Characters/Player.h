#pragma once
#include "Character.h"

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

            public:
                Player(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), sf::Vector2f si = sf::Vector2f(0.0, 0.0), Maps::QuadTree* q = nullptr);
                virtual ~Player();

                void loseHP(const int hp);
                void gainHP(const int hp);
                void loseExp(const int exp);
                void gainExp(const int exp);

                void loseMoney(const int money);
                void gainMoney(const int money);

                void updateStats();
                void updateLevel();
                void update();

                void move();

                void executeJump();

                void execute();
            };
        }
    }
}