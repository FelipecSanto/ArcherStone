#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Managers/GraphicsManager.h"
#include "../Mapa/QuadTree.h"

class Entity {
protected:
    sf::RectangleShape shape;
    sf::Texture texture;
    sf::Vector2f position;
    const sf::Vector2f size;
    sf::Vector2f velocity;

    const std::string type;
    std::string status;

    float acelaracao;

    GraphicsManager* graphicsManager;
    QuadTree* quadtree;

    bool estaNoChao;

public:
    Entity(std::string ty = "", sf::Vector2f pos = sf::Vector2f(0.0, 0.0), sf::Vector2f si = sf::Vector2f(0.0, 0.0), QuadTree* q = nullptr);
    ~Entity();

    const sf::Texture getTexture();

    void setPosition(const sf::Vector2f pos);
    const sf::Vector2f getPosition();

    const sf::Vector2f getSize();

    void setVelocity(const sf::Vector2f vel);
    const sf::Vector2f getVelocity();

    const std::string getType();

    void setStatus(const std::string sta);
    const std::string getStatus();

    void setEstaNoChao(const bool chao);
    const bool getEstaNoChao();

    sf::RectangleShape getShape();

    void design();

    void gravidade();

    void atualizarQuadtree();

    virtual void execute() = 0;

    void colision(Entity* otherEntity, sf::FloatRect intersects);

};