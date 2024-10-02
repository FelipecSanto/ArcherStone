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
                jumpClock(),
                plObserver(new Observers::PlayerObserver(this))
            {
                eventsMgr->addObserver(plObserver);
                //texture = *graphicsMgr->loadTexture("Assets/Player.png");
                //shape.setTexture(&texture);
            }

            Player::~Player()
            {
                delete plObserver;
                plObserver = nullptr;
            }

            void Player::setJumping(const bool jump)
            {
                jumping = jump;
            }

            const bool Player::getJumping()
            {
                return jumping;
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
                updateQuadtree();
                updateStats();
                updateLevel();
            }

            void Player::move(std::string movement)
            {
                if(acceleration != 0.0f)
                    onGround = false;

                if(movement == "DOWNWARD" && velocity.y <= 20.0f) {
                    velocity.y += 4.0f;
                }

                if(movement == "LEFTWARD" && velocity.x >= -4.0f) {
                    velocity.x -= 1.0f;
                }
                else if(movement == "RIGHTWARD" && velocity.x <= 4.0f) {
                     velocity.x += 1.0f;
                }
               
                if(movement == "LEFTWARD FLYING" && velocity.x >= -2.0f) {
                    velocity.x -= 0.5f;
                }
                else if(movement == "RIGHTWARD FLYING" && velocity.x <= 2.0f) {
                    velocity.x += 0.5f;
                }

                shape.move(velocity);
            }

            void Player::stop(std::string direction)
            {
                if(direction == "X")
                    velocity.x = 0.0f;
                else
                    velocity.y = 0.0f;
            }

            void Player::restartJumpClock()
            {
                jumpClock.restart();
            }

            void Player::executeJump()
            {
                if(jumping) {
                    dtJump = jumpClock.getElapsedTime().asSeconds();
                    velocity.y = -VELOCIDADE_PULO + GRAVIDADE*dtJump;

                    if(onGround) {
                        jumping = false;
                        jumpClock.restart();
                    }
                }

                shape.move(velocity);
            }

            void Player::execute()
            {
                update();
                executeJump();
                applyGravity();
                design();
            }
        }
    }
}
