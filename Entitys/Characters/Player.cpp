#include "Player.h"

namespace Entitys
{
    namespace Characters
    {
        namespace Players
        {
            Player::Player(sf::Vector2f pos, sf::Vector2f si, Maps::QuadTree* q):
                Character("PLAYER", pos, si, q),
                health(100),
                maxHealth(100),
                damage(10),
                level(1),
                experience(0),
                experienceNext(100),
                Points(0),
                dtJump(0.0f),
                jumping(false),
                jumpClock()
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
                updateQuadtree();
                updateStats();
                updateLevel();
            }

            void Player::move()
            {
                if(acceleration != 0.0f)
                    onGround = false;

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && onGround) {
                    jumpClock.restart();
                    jumping = true;
                    onGround = false;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && velocity.y <= 20.0f && !onGround) {
                    velocity.y += 4.0f;
                }

                if(jumping) {
                    executeJump();
                }

                if(onGround) {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        if(velocity.x >= -4.0f)
                            velocity.x -= 1.0f;
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        if(velocity.x <= 4.0f)
                            velocity.x += 1.0f;
                    }
                }
                else {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        if(velocity.x >= -2.0f)
                            velocity.x -= 0.5f;
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        if(velocity.x <= 2.0f)
                            velocity.x += 0.5f;
                    }
                }

                shape.move(velocity);

                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
                    !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                    !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                    !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    velocity.x = 0.0f;
                    velocity.y = 0.0f;
                }
            }

            void Player::executeJump()
            {
                dtJump = jumpClock.getElapsedTime().asSeconds();
                velocity.y = -VELOCIDADE_PULO + GRAVIDADE*dtJump;

                if(onGround) {
                    jumping = false;
                    jumpClock.restart();
                }
            }

            void Player::execute()
            {
                update();
                applyGravity();
                design();
            }
        }
    }
}
