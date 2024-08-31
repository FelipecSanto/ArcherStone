#include "QuadTree.h"

namespace Maps
{
    QuadTree::QuadTree(float posX, float posY, float largura, float altura, int nivel): 
    posX(posX), 
    posY(posY), 
    largura(largura), 
    altura(altura), 
    nivel(nivel), 
    area(posX, posY, largura, altura)
    {
        for(int i = 0; i < 4; i++)
            nos[i] = nullptr;
    }

    QuadTree::~QuadTree(){
        clearEntities();
        for(int i = 0; i < 4; i++)
            if(nos[i]!= nullptr){
                delete nos[i];
                nos[i] = nullptr;
            }
    }


    void QuadTree::updateQuad(Entitys::Entity* entity, sf::FloatRect area){
        if (this->area.intersects(area)) {
            // Se a Entity está no mesmo quadrante, não precisamos fazer nada
            if(nos[0] != nullptr){
                for (int i = 0; i < 4; i++) {
                    if (!nos[i]->area.intersects(area)) {
                        // Se a Entity não está no quadrante do filho, removemos ela
                        nos[i]->deleteEntity(entity, area);
                    }
                    else{
                        // Se a Entity está no quadrante do filho, atualizamos o quadrante
                        nos[i]->updateQuad(entity, area);
                    }
                }
            }
            return;
        }

        // Se a Entity se moveu para um quadrante diferente, precisamos removê-la e reinseri-la
        deleteEntity(entity, area);
        insertEntity(entity, area);
    }

    void QuadTree::deleteEntity(Entitys::Entity* Entity, sf::FloatRect area){
        if(this->area.intersects(area)){
            entitys.erase(Entity);

            if(nos[0] != nullptr){
                for(int i = 0; i < 4; i++){
                    nos[i]->deleteEntity(Entity, area);
                }
            }
        }
    }


    void QuadTree::getEntitiesInArea(std::unordered_set<Entitys::Entity*>* retorno, sf::FloatRect area){
        if(this->area.intersects(area)){
            for(Entitys::Entity* e : entitys) {
                retorno->insert(e);
            }
            
            if(nos[0] != nullptr){
                for(int i = 0; i < 4; i++){
                    nos[i]->getEntitiesInArea(retorno, area);
                }
            }
        }
    }

    void QuadTree::subdivide() {

        float meiaLargura = largura/2;
        float meiaAltura = altura/2;

        nos[0] = new QuadTree(posX, posY, meiaLargura, meiaAltura, nivel+1);
        nos[1] = new QuadTree(posX + meiaLargura, posY, meiaLargura, meiaAltura, nivel+1);
        nos[2] = new QuadTree(posX, posY + meiaAltura, meiaLargura, meiaAltura, nivel+1);
        nos[3] = new QuadTree(posX + meiaLargura, posY + meiaAltura, meiaLargura, meiaAltura, nivel+1);
    }

    void QuadTree::clearEntities(){
        entitys.clear();

        if(nos[0] != nullptr)
            for (int i = 0; i < 4; i++){
                nos[i]->clearEntities();
            }
    }

    void QuadTree::insertEntity(Entitys::Entity* Entity, sf::FloatRect area) {
        if (nos[0] != nullptr) {
            for(int i = 0; i < 4; i++) {
                if (nos[i]->area.intersects(area)) {
                    nos[i]->insertEntity(Entity, area);
                }
            }
        }

        if (entitys.size() < QT_MAX_EntityS || nivel == QT_MAX_NIVEIS) {
            entitys.insert(Entity);
        } else {
            if (nos[0] == nullptr) {
                subdivide();
            }

            for(int i = 0; i < 4; i++) {
                if (nos[i]->area.intersects(area)) {
                    nos[i]->insertEntity(Entity, area);
                }
            }
        }
    }
}