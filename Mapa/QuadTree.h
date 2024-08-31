#pragma once
#include <vector>
#include <unordered_set>
#include <SFML/Graphics.hpp>

#define QT_MAX_EntityS 3 // quantidade maxima de Entitys que um no pode ter
#define QT_MAX_NIVEIS 10 // quantidade maxima de niveis que a quadtree pode ter (ALTURA DA ARVORE) (obbs: n está limitado ainda)

namespace Entitys
{
    class Entity;
}

namespace Maps
{
    class QuadTree {
        private:
            int nivel;
            std::unordered_set<Entitys::Entity*> entitys;
            QuadTree* nos[4];
            float posX, posY, largura, altura;
            sf::FloatRect area;

        public:
            QuadTree(float posX = 0.0f, float posY = 0.0f, float largura = 0.0f, float altura = 0.0f, int nivel = 0);
            ~QuadTree();

            void insertEntity(Entitys::Entity* Entity, sf::FloatRect area);
            void subdivide();
            void clearEntities();
            void getEntitiesInArea(std::unordered_set<Entitys::Entity*>* retorno, sf::FloatRect area);
            void updateQuad(Entitys::Entity* Entity, sf::FloatRect area);
            void deleteEntity(Entitys::Entity* Entity, sf::FloatRect area);
    };
}