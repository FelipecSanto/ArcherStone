#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../nlohmann/json.hpp"
#include "../nlohmann/json_fwd.hpp"
#include "../Entitys/Characters/Player.h"
#include "../Entitys/Platform.h"
#include "QuadTree.h"
#include <vector>
#include <fstream>
#include <string>

namespace Maps
{
    class Tilemap{
        private:
            nlohmann::json map; // mapa.json
            std::multimap<std::string, Entitys::Entity*>* entitys; // mapa de Entitys com a chave sendo o tipo (referencia da FaseState)
            sf::Texture* map_texture;  
            Maps::QuadTree* q; // quadtree (referencia da FaseState)

        public:
            Tilemap(Maps::QuadTree* q);
            ~Tilemap();

            void loadMap(std::string mapJson);
            void createMap(std::string mapFilePath, std::multimap<std::string, Entitys::Entity*>* entitys, sf::Texture* map_texture);
            Entitys::Entity* createEntity (sf::Vector2f pos, sf::Vector2f size, int type);
            nlohmann::json getMap();
    };
}