#include "Entity.h"

Entity::Entity(std::string ty, sf::Vector2f pos, sf::Vector2f si, QuadTree* q):
    shape(sf::RectangleShape(si)),
    type(ty),
    status(""),
    position(pos),
    size(si),
    velocity(sf::Vector2f(0, 0)),
    texture(),
    graphicsManager(GraphicsManager::getInstance()),
    acelaracao(0.0f),
    quadtree(q),
    estaNoChao(false)
{
    shape.setPosition(position);
}

Entity::~Entity()
{
}

const sf::Texture Entity::getTexture()
{
    return texture;
}

void Entity::setPosition(const sf::Vector2f pos)
{
    shape.setPosition(position);
}

const sf::Vector2f Entity::getPosition()
{
    return shape.getPosition();
}

const sf::Vector2f Entity::getSize()
{
    return size;
}

void Entity::setVelocity(const sf::Vector2f vel)
{
    velocity = vel;
}

const sf::Vector2f Entity::getVelocity()
{
    return velocity;
}

const std::string Entity::getType()
{
    return type;
}

void Entity::setStatus(const std::string sta)
{
    status = sta;
}

const std::string Entity::getStatus()
{
    return status;
}

void Entity::setEstaNoChao(const bool chao)
{
    estaNoChao = chao;
}

const bool Entity::getEstaNoChao()
{
    return estaNoChao;
}

sf::RectangleShape Entity::getShape()
{
    return shape;
}

void Entity::design()
{
    graphicsManager->draw(shape);
}

void Entity::gravidade()
{
    if(acelaracao < 10.0f)
        acelaracao += 0.1f;
    
    shape.move(sf::Vector2f(0, acelaracao));
}

void Entity::atualizarQuadtree()
{
    if(position != shape.getPosition()) {
        quadtree->atualizar(this, shape.getGlobalBounds());
        position = shape.getPosition();
    }
}

void Entity::colision(Entity *otherEntity, sf::FloatRect intersects)
{
    // Calculate the overlap between the player and the otherEntity
    sf::Vector2f overlap = sf::Vector2f(0, 0);
    if (intersects.width < intersects.height) {
        if (shape.getPosition().x < otherEntity->getPosition().x) {
            overlap.x = -intersects.width;
        } else {
            overlap.x = intersects.width;
        }
    } else {
        if (shape.getPosition().y < otherEntity->getPosition().y) {
            overlap.y = -intersects.height;
            acelaracao = 0.0f;
            estaNoChao = true;
        } else {
            overlap.y = intersects.height;
        }
    }

    // Update the player's position based on the overlap
    if(type == "PLAYER") {
        shape.move(overlap);
    }
}
