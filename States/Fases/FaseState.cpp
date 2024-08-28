#include "FaseState.h"

FaseState::FaseState(std::string tilemapFaseState):
GameState("FaseState"),
quadtree(0, 0, 1920, 1080), 
tilemap(&quadtree),
graphicsMan(GraphicsManager::getInstance())
{
    tilemap.criarMapa(tilemapFaseState, &entitys, &textura_mapa);
    sprite_mapa.setTexture(textura_mapa);

    for (const auto& pair : entitys) {
        if(pair.second->getType() != "PLATFORM")
            quadtree.inserir(pair.second, pair.second->getShape().getGlobalBounds());
    }

    collisionMan->setQuadTree(&quadtree);

    graphicsManager->loadTexture("../Assets/Backgrounds/Fase.png", &fundo);
    corpo.setSize(graphicsManager->getWindowSize());
    corpo.setPosition(0, 0);
    corpo.setTexture(&fundo);
    corpo.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
}

FaseState::~FaseState() {
    
}

void FaseState::executeEntitys() {
    for (const auto& pair : entitys) {
        pair.second->execute();
    }
}

void FaseState::draw() {
    graphicsManager->draw(corpo);
    graphicsMan->draw(sprite_mapa);
}

void FaseState::execute() {

    draw();
    executeEntitys();
    collisionMan->executar(&entitys);
}