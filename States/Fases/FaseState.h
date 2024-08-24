#pragma once
#include "GameState.h"
#include "../../Mapa/tilemap.h"

class FaseState : public GameState {
    private:
        std::multimap<std::string, Entity*> entitys;
        sf::Texture textura_mapa;
        sf::Sprite sprite_mapa;
       
        Tilemap tilemap; // responsavel por criar o mapa
        QuadTree quadtree; // responsavel por dividir o mapa em quadrantes
        GraphicsManager* graphicsMan;

    public:
        FaseState(std::string tilemapFaseState);
        ~FaseState();

        void executeEntitys();
        void draw();
        void execute();
};