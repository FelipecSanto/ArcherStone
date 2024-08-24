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

class Tilemap{
    private:
        nlohmann::json mapa; // mapa.json
        std::multimap<std::string, Entity*>* entitys; // mapa de Entitys com a chave sendo o tipo (referencia da FaseState)
        sf::Texture* textura_mapa;  
        QuadTree* q; // quadtree (referencia da FaseState)

    public:
        Tilemap(QuadTree* q);
        ~Tilemap();

        void carregarMapa(std::string mapJson);
        void criarMapa(std::string caminhoMapa, std::multimap<std::string, Entity*>* entitys, sf::Texture* textura_mapa);
        Entity* criarEntity (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
        nlohmann::json getMapa();
};
