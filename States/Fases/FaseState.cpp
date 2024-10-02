#include "FaseState.h"

namespace States
{
    namespace Fases
    {
        FaseState::FaseState(std::string tilemapFaseState):
        State("FaseState"),
        quadtree(0, 0, 1920, 1080), 
        tilemap(&quadtree),
        graphicsMan(Managers::GraphicsManager::getInstance()),
        corpo(),
        fundo(),
        collisionMan(Managers::CollisionManager::getInstance()),
        observer(new Observers::FaseStateObserver(this))
        {
            eventsMgr->addObserver(observer);
            tilemap.createMap(tilemapFaseState, &entitys, &map_texture);
            sprite_mapa.setTexture(map_texture);

            for (const auto& pair : entitys) {
                if(pair.second->getType() != "PLATFORM")
                    quadtree.insertEntity(pair.second, pair.second->getShape().getGlobalBounds());
            }

            collisionMan->setQuadTree(&quadtree);

            graphicsMgr->loadTexture("../Assets/Backgrounds/Fase.png", &fundo);
            corpo.setSize(graphicsMgr->getWindowSize());
            corpo.setPosition(0, 0);
            corpo.setTexture(&fundo);
            corpo.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
        }

        FaseState::~FaseState() {
            delete observer;
            observer = nullptr;
        }

        void FaseState::activateObserver()
        {
            observer->setActivated(true);
        }

        void FaseState::deactivateObserver()
        {
            observer->setActivated(false);
        }

        void FaseState::executeEntitys() {
            for (const auto& pair : entitys) {
                pair.second->execute();
            }
        }

        void FaseState::draw() {
            graphicsMgr->draw(corpo);
            graphicsMan->draw(sprite_mapa);
        }

        void FaseState::execute() {

            draw();
            executeEntitys();
            collisionMan->execute(&entitys);
        }
    }
}