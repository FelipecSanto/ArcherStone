#pragma once
#include <unordered_map>
#include <functional>
#include <vector>
#include <string>
#include "../Entitys/Characters/Player.h"
#include "../Entitys/Platform.h"

class CollisionManager{
    private:
        std::unordered_map<std::string, std::function<void(Entity*, Entity*, sf::FloatRect)>> mapaColisoes;

        static CollisionManager* instancia;

        QuadTree* quadtree;

        CollisionManager();

    public:
        ~CollisionManager();

        static CollisionManager* getInstance();

        void setQuadTree(QuadTree* q);

        void criarMapaColisoes();
        void verificarColisao(Entity* ent1, Entity* ent2);
        void executar(std::multimap<std::string, Entity*>* entitys);
        //void executarBruto(std::vector<Entity*>* Entitys);
};