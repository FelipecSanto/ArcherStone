#include "tilemap.h"

Tilemap::Tilemap(QuadTree* q): 
q(q) 
{
}

Tilemap::~Tilemap() {
    q = nullptr;
    entitys = nullptr;
    textura_mapa = nullptr;
}

void Tilemap::carregarMapa(std::string mapJson) {
    std::ifstream arquivo(mapJson);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
}

void Tilemap::criarMapa(std::string caminhoMapa, std::multimap<std::string, Entity*>* entitys, sf::Texture* textura_mapa) {
    
    carregarMapa(caminhoMapa);  // carrega arquivo json
    this->entitys = entitys; // referencia para o mapa de entitys da FaseState
    
    // .json tenha o mesmo nome do .png e ambos estejam na mesma pasta

    this->textura_mapa = textura_mapa; // referencia para a textura do mapa da FaseState
    textura_mapa->loadFromFile(caminhoMapa.substr(0, caminhoMapa.find_last_of(".")) + ".png");

    // Pega as informações do mapa

    int sizeTiled = mapa["tilewidth"];
    int width = mapa["width"];
    int height = mapa["height"];
    
    int indice = 0;

    //Loop para criar as entitys 0 = vazio, -1 = jogador e outros valores são entitys diversas
   
    /*for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId != 0){
                sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                sf::Vector2f tamanho(sizeTiled, sizeTiled);
                entitys->push_back(criarEntity(posicao, tamanho, tileId));
            }
        }
    }*/



    // Loop para criar a fase, mas agora com Entity de tamanhos diversos;

    /*for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            long long int tileId = mapa["layers"][0]["data"][indice];
            if(tileId != 0){
                int mult = 1;
                while(tileId == mapa["layers"][0]["data"][++indice]){
                    mult++;
                }
                sf::Vector2f posicao(x*sizeTiled, y*sizeTiled);
                x += mult - 1;

                sf::Vector2f tamanho(sizeTiled*mult, sizeTiled);
                Entity* entity = criarEntity(posicao, tamanho, tileId);
                (*entitys)[entity->getType()] = entity;
               
            }else
                indice++;
        }
    }*/


   for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (indice >= mapa["layers"][0]["data"].size()) {
                // Verifique se o índice está dentro dos limites
                break;
            }

            long long int tileId = mapa["layers"][0]["data"][indice];
            if (tileId != 0) {
                int mult = 1;
                while (indice + 1 < mapa["layers"][0]["data"].size() && tileId == mapa["layers"][0]["data"][indice + 1] && x + mult < width) {
                    mult++;
                    indice++;
                }
                sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                x += mult - 1;

                sf::Vector2f tamanho(sizeTiled * mult, sizeTiled);
                Entity* entity = criarEntity(posicao, tamanho, tileId);
                entitys->insert(std::make_pair(entity->getType(), entity));
            }
            indice++;
        }
    }
}

Entity* Tilemap::criarEntity(sf::Vector2f posicao, sf::Vector2f tamanho, int tipo) {
    if (tipo == -1) {
        return new Player(posicao, tamanho, q);
    }
    else {
        return new Platform(posicao, tamanho, q);
    }
}

nlohmann::json Tilemap::getMapa()
{
    return mapa;
}
