#include "CollisionManager.h"

namespace Managers
{
    CollisionManager* CollisionManager::instance = nullptr;

    CollisionManager::CollisionManager() {
        createCollisionMap();
    }

    CollisionManager::~CollisionManager() {
        quadtree->clearEntities();
        delete quadtree;
        quadtree = nullptr;
    }

    CollisionManager* CollisionManager::getInstance() {
        if(instance == nullptr){
            instance = new CollisionManager();
        }
        return instance;
    }

    void CollisionManager::setQuadTree(Maps::QuadTree *q) {
        quadtree = q;
    }

    void CollisionManager::createCollisionMap() {
        collisionMap["PLAYER"] = [](Entitys::Entity* ent, Entitys::Entity* player, sf::FloatRect intersect) {
            ent->colision(dynamic_cast<Entitys::Characters::Players::Player*>(player), intersect);
        };
        collisionMap["PLATFORM"] = [](Entitys::Entity* ent, Entitys::Entity* platform, sf::FloatRect intersect){
            ent->colision(dynamic_cast<Entitys::Platform*>(platform), intersect);
        };
    }


    void CollisionManager::checkCollision(Entitys::Entity* ent1, Entitys::Entity* ent2) {
        sf::FloatRect rect2 = ent2->getShape().getGlobalBounds();
        sf::FloatRect rect1 = ent1->getShape().getGlobalBounds();
        sf::FloatRect intersects;

        if(rect1.intersects(rect2, intersects)){
            collisionMap[ent2->getType()](ent1, ent2, intersects);
            collisionMap[ent1->getType()](ent2, ent1, intersects);
        }
    }

    void CollisionManager::execute(std::multimap<std::string, Entitys::Entity*>* entitys) {

        for (const auto& pair : *entitys) {

            std::unordered_set<Entitys::Entity*> collisionEntities;

            quadtree->getEntitiesInArea(&collisionEntities, pair.second->getShape().getGlobalBounds());

            for(Entitys::Entity* e : collisionEntities){
                if(pair.second != e){
                    checkCollision(pair.second, e);
                }
            }
        }
    }
}