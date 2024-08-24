#pragma once
#include "Character.h"

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

public:
    Player(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), sf::Vector2f si = sf::Vector2f(0.0, 0.0), QuadTree* q = nullptr);
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

    void execute();
};