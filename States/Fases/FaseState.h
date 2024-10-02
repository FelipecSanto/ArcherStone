#pragma once
#include "../State.h"
#include "../../Mapa/tilemap.h"
#include "../../Managers/CollisionManager.h"
#include "../../Observers/FaseStateObserver.h"

namespace States
{
    namespace Fases
    {
        class FaseState : public State {
            private:
                std::multimap<std::string, Entitys::Entity*> entitys;

                sf::Texture map_texture;
                sf::Sprite sprite_mapa;
                sf::RectangleShape corpo;
                sf::Texture fundo;

                Maps::Tilemap tilemap; // responsavel por criar o mapa
                Maps::QuadTree quadtree; // responsavel por dividir o mapa em quadrantes
                
                Managers::GraphicsManager* graphicsMan;
                Managers::CollisionManager* collisionMan;

                Observers::FaseStateObserver* observer;

            public:
                FaseState(std::string tilemapFaseState);
                ~FaseState();

                void executeEntitys();
                void draw();
                void execute();
        };
    }
}