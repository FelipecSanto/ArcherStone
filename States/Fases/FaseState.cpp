#include "FaseState.h"

namespace States
{
    namespace Fases
    {
        FaseState::FaseState(std::string tilemapFaseState):
        GameState("FaseState"),
        quadtree(0, 0, 1920, 1080), 
        tilemap(&quadtree),
        graphicsMan(Managers::GraphicsManager::getInstance())
        {
            tilemap.createMap(tilemapFaseState, &entitys, &map_texture);
            sprite_mapa.setTexture(map_texture);

            for (const auto& pair : entitys) {
                if(pair.second->getType() != "PLATFORM")
                    quadtree.insertEntity(pair.second, pair.second->getShape().getGlobalBounds());
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
            collisionMan->execute(&entitys);
        }
    }
}