#include "Player.h"

Player::Player(sf::Vector2f pos, sf::Vector2f si, QuadTree* q):
    Character("PLAYER", pos, si, q),
    health(100),
    maxHealth(100),
    damage(10),
    level(1),
    experience(0),
    experienceNext(100),
    Points(0)
{
    //texture = *graphicsManager->loadTexture("Assets/Player.png");
    //shape.setTexture(&texture);
}

Player::~Player()
{
}

void Player::loseHP(const int hp)
{

}

void Player::gainHP(const int hp)
{

}

void Player::loseExp(const int exp)
{
}

void Player::gainExp(const int exp)
{
}

void Player::loseMoney(const int money)
{
}

void Player::gainMoney(const int money)
{
}

void Player::updateStats()
{
}

void Player::updateLevel()
{
}

void Player::update()
{
    move();
    updateStats();
    updateLevel();
}

void Player::move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        shape.move(0, -8);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        shape.move(0, 8);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        shape.move(-8, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        shape.move(8, 0);
}

void Player::execute()
{
    update();
    gravidade();
    design();
}
