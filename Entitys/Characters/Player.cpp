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
    if(acelaracao == 0.0f)
        estaNoChao = true;

    if(pulando) {
        pulo();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoChao) {
        pulando = true;
        estaNoChao = false;
        //acelaracao = 0.0001f;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && velocity.y <= 20.0f && !estaNoChao) {
        velocity.y += 4.0f;
        shape.move(0, velocity.y);
    }

    //std::cout << "Pulando: " << pulando << std::endl;
    //std::cout << "No chao: " << estaNoChao << std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(velocity.x >= -8.0f)
            velocity.x += -2.0f;
        shape.move(velocity.x, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(velocity.x <= 8.0f)
            velocity.x += 2.0f;
        shape.move(velocity.x, 0);
    }

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
    shape.move(0, velocity.y);

    if(estaNoChao) {
        pulando = false;
        clockPulo.restart();
    }
}

void Player::execute()
{
    update();
    if(!pulando)
        gravidade();
    design();
}
