#pragma once
#include <unordered_map>
#include <functional>
#include "../Entitys/Characters/Player.h"
#include "../Entitys/Platform.h"

namespace Managers 
{
    class CollisionManager {
        private:
            std::unordered_map<std::string, std::function<void(Entitys::Entity*, Entitys::Entity*, sf::FloatRect)>> collisionMap;

            static CollisionManager* instance;

            Maps::QuadTree* quadtree;

            CollisionManager();

        public:
            ~CollisionManager();

            static CollisionManager* getInstance();

            void setQuadTree(Maps::QuadTree* q);

            void createCollisionMap();
            void checkCollision(Entitys::Entity* ent1, Entitys::Entity* ent2);
            void execute(std::multimap<std::string, Entitys::Entity*>* entitys);
    };
}