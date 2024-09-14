#include "PlayerObserver.h"
#include "../Entitys/Characters/Player.h"

namespace Observers
{
    PlayerObserver::PlayerObserver(Entitys::Characters::Players::Player* pl):
    Observer(),
    player(pl)
    {
    }

    PlayerObserver::~PlayerObserver()
    {
    }

    void PlayerObserver::keyPressed(const sf::Keyboard::Key key)
    {
        switch (key)
        {
            case sf::Keyboard::Up: {
                if(player->getOnGround()) {
                    player->restartJumpClock();
                    player->setJumping(true);
                    player->setOnGround(false);
                }
            }
                break;
        
            case sf::Keyboard::Down: {
                if(!player->getOnGround())
                    player->move("DOWNWARD");
            }
                break;

            case sf::Keyboard::Left: {
                if(player->getOnGround())
                    player->move("LEFTWARD");
                else
                    player->move("LEFTWARD FLYING");
            }
                break;

            case sf::Keyboard::Right:{
                if(player->getOnGround())
                    player->move("RIGHTWARD");
                else
                    player->move("RIGHTWARD FLYING");
            }
                break;
        
            default:
                break;
        }
    }

    void PlayerObserver::keyReleased(const sf::Keyboard::Key key)
    {
        if(key == sf::Keyboard::Left || key == sf::Keyboard::Right)
            player->stop("X");
        else if(key == sf::Keyboard::Up || key == sf::Keyboard::Down)
            player->stop("Y");
    }

    void PlayerObserver::mousePressed(const sf::Mouse::Button mouseButton)
    {
    }

    void PlayerObserver::mouseReleased(const sf::Mouse::Button mouseButton)
    {
    }
}