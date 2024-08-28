#include "CollisionManager.h"

CollisionManager* CollisionManager::instancia = nullptr;

CollisionManager::CollisionManager() {
    criarMapaColisoes();
}

CollisionManager::~CollisionManager(){
    quadtree->limpar();
    delete quadtree;
    quadtree = nullptr;
}

CollisionManager* CollisionManager::getInstance(){
    if(instancia == nullptr){
        instancia = new CollisionManager();
    }
    return instancia;
}

void CollisionManager::setQuadTree(QuadTree *q)
{
    quadtree = q;
}

void CollisionManager::criarMapaColisoes(){
    mapaColisoes["PLAYER"] = [](Entity* ent, Entity* jogador, sf::FloatRect intersect) {
        ent->colision(dynamic_cast<Player*>(jogador), intersect);
    };
    mapaColisoes["PLATFORM"] = [](Entity* ent, Entity* plataforma, sf::FloatRect intersect){
        ent->colision(dynamic_cast<Platform*>(plataforma), intersect);
    };
}


void CollisionManager::verificarColisao(Entity* ent1, Entity* ent2){
    sf::FloatRect rect2 = ent2->getShape().getGlobalBounds();
    sf::FloatRect rect1 = ent1->getShape().getGlobalBounds();
    sf::FloatRect intersects;

    if(rect1.intersects(rect2, intersects)){
        mapaColisoes[ent2->getType()](ent1, ent2, intersects);
        mapaColisoes[ent1->getType()](ent2, ent1, intersects);
    }
    else{
        if(ent1->getType() == "PLAYER"){
            ent1->setEstaNoChao(false);
        }
        else if(ent2->getType() == "PLAYER"){
            ent2->setEstaNoChao(false);
        }
    }
}

/*void CollisionManager::executarBruto(std::vector<Entity*>* Entitys){
    int cont = 0;
    for(int i = 0; i < Entitys->size(); i++){
        Entity* ent1 = Entitys->at(i);
        for(int j = i + 1; j < Entitys->size(); j++){
            Entity* ent2 = Entitys->at(j);
            verificarColisao(ent1, ent2);
            cont++;
        }
    }
}*/

void CollisionManager::executar(std::multimap<std::string, Entity*>* entitys){


    for (const auto& pair : *entitys) {
        //Pq usar unordered_set?
        std::unordered_set<Entity*> retorno;
        // O que faz?
        quadtree->recuperar(&retorno, pair.second->getShape().getGlobalBounds());
        for(Entity* e : retorno){
            if(pair.second != e){
                // Verifica se houve colisao
                verificarColisao(pair.second, e);
            }
        }
    }
}