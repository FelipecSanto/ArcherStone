#include "QuadTree.h"

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
    limpar();
    for(int i = 0; i < 4; i++)
        if(nos[i]!= nullptr){
            delete nos[i];
            nos[i] = nullptr;
        }
}


void QuadTree::atualizar(Entity* entity, sf::FloatRect area){
    if (this->area.intersects(area)) {
        // Se a Entity está no mesmo quadrante, não precisamos fazer nada
        if(nos[0] != nullptr){
            for (int i = 0; i < 4; i++) {
                if (!nos[i]->area.intersects(area)) {
                    // Se a Entity não está no quadrante do filho, removemos ela
                    nos[i]->remover(entity, area);
                }
                else{
                    // Se a Entity está no quadrante do filho, atualizamos o quadrante
                    nos[i]->atualizar(entity, area);
                }
            }
        }
        return;
    }

    // Se a Entity se moveu para um quadrante diferente, precisamos removê-la e reinseri-la
    remover(entity, area);
    inserir(entity, area);
}

void QuadTree::remover(Entity* Entity, sf::FloatRect area){
    if(this->area.intersects(area)){
        entitys.erase(Entity);

        if(nos[0] != nullptr){
            for(int i = 0; i < 4; i++){
                nos[i]->remover(Entity, area);
            }
        }
    }
}


void QuadTree::recuperar(std::unordered_set<Entity*>* retorno, sf::FloatRect area){
    if(this->area.intersects(area)){
        for(Entity* e : entitys){
            retorno->insert(e);
        }
        
        if(nos[0] != nullptr){
            for(int i = 0; i < 4; i++){
                nos[i]->recuperar(retorno, area);
            }
        }
    }
}

void QuadTree::dividir(){
    float meiaLargura = largura/2;
    float meiaAltura = altura/2;
    nos[0] = new QuadTree(posX, posY, meiaLargura, meiaAltura, nivel+1);
    
    sf::RectangleShape shape1(sf::Vector2f(meiaLargura, meiaAltura));
    //shape1.setPosition(posX, posY);
    //shape1.setFillColor(sf::Color(20*(nivel+1), 0, 0, 80));
    //shapes.push_back(shape1);
    
    nos[1] = new QuadTree(posX + meiaLargura, posY, meiaLargura, meiaAltura, nivel+1);

    sf::RectangleShape shape2(sf::Vector2f(meiaLargura, meiaAltura));
    //shape2.setPosition(posX + meiaLargura, posY);
    //shape2.setFillColor(sf::Color(20*(nivel+1), 0, 0, 80));
    //shapes.push_back(shape2);

    nos[2] = new QuadTree(posX, posY + meiaAltura, meiaLargura, meiaAltura, nivel+1);

    sf::RectangleShape shape3(sf::Vector2f(meiaLargura, meiaAltura));
    //shape3.setPosition(posX, posY + meiaAltura);
    //shape3.setFillColor(sf::Color(20*(nivel+1), 0, 0, 80));
    //shapes.push_back(shape3);

    nos[3] = new QuadTree(posX + meiaLargura, posY + meiaAltura, meiaLargura, meiaAltura, nivel+1);

    sf::RectangleShape shape4(sf::Vector2f(meiaLargura, meiaAltura));
    //shape4.setPosition(posX + meiaLargura, posY + meiaAltura);
    //shape4.setFillColor(sf::Color(20*(nivel+1), 0, 0, 80));
    //shapes.push_back(shape4);

}

void QuadTree::limpar(){
    entitys.clear();

    if(nos[0] != nullptr)
        for (int i = 0; i < 4; i++){
            nos[i]->limpar();
        }
}

void QuadTree::inserir(Entity* Entity, sf::FloatRect area) {
    if (nos[0] != nullptr) {
        for(int i = 0; i < 4; i++) {
            if (nos[i]->area.intersects(area)) {
                nos[i]->inserir(Entity, area);
            }
        }
    }

    if (entitys.size() < QT_MAX_EntityS || nivel == QT_MAX_NIVEIS) {
        entitys.insert(Entity);
    } else {
        if (nos[0] == nullptr) {
            dividir();
        }

        for(int i = 0; i < 4; i++) {
            if (nos[i]->area.intersects(area)) {
                nos[i]->inserir(Entity, area);
            }
        }
    }
}