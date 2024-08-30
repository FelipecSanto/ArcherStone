#include "Player.h"

Player::Player(sf::Vector2f pos, sf::Vector2f si, QuadTree* q):
    Character("PLAYER", pos, si, q),
    health(100),
    maxHealth(100),
    damage(10),
    level(1),
    experience(0),
    experienceNext(100),
    Points(0),
    dtPulo(0.0f),
    pulando(false),
    clockPulo()
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
    atualizarQuadtree();
    updateStats();
    updateLevel();
}

void Player::move()
{
    if(acelaracao != 0.0f)
        estaNoChao = false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoChao) {
        clockPulo.restart();
        pulando = true;
        estaNoChao = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && velocity.y <= 20.0f && !estaNoChao) {
        velocity.y += 4.0f;
    }

    //std::cout << "Pulando: " << pulando << std::endl;

    if(pulando) {
        pulo();
    }

    if(estaNoChao) {
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

void Player::pulo()
{
    dtPulo = clockPulo.getElapsedTime().asSeconds();
    velocity.y = -VELOCIDADE_PULO + GRAVIDADE*dtPulo;

    if(estaNoChao) {
        pulando = false;
        clockPulo.restart();
    }
}

void Player::execute()
{
    update();
    gravidade();
    design();
}
