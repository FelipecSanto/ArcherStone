#pragma once
#include "GameState.h"
#include "../../Mapa/tilemap.h"

namespace States
{
    namespace Fases
    {
        class FaseState : public GameState {
            private:
                std::multimap<std::string, Entitys::Entity*> entitys;
                sf::Texture map_texture;
                sf::Sprite sprite_mapa;
            
                Maps::Tilemap tilemap; // responsavel por criar o mapa
                Maps::QuadTree quadtree; // responsavel por dividir o mapa em quadrantes
                Managers::GraphicsManager* graphicsMan;

            public:
                FaseState(std::string tilemapFaseState);
                ~FaseState();

                void executeEntitys();
                void draw();
                void execute();
        };
    }
}