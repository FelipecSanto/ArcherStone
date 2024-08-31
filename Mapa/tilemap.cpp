#include "tilemap.h"

namespace Maps
{
    Tilemap::Tilemap(Maps::QuadTree* q): 
    q(q),
    entitys(nullptr),
    map_texture(nullptr),
    map()
    {
    }

    Tilemap::~Tilemap() {
        q = nullptr;
        entitys = nullptr;
        map_texture = nullptr;
    }

    void Tilemap::loadMap(std::string mapJson) {
        std::ifstream arquivo(mapJson);
        
        if(!arquivo.is_open()){
            std::cerr << "ERROR: Tilemap::loadMap: Não foi possível abrir o arquivo" << std::endl;
            return;
        }

        arquivo >> map;
        arquivo.close();
    }

    void Tilemap::createMap(std::string mapFilePath, std::multimap<std::string, Entitys::Entity*>* entitys, sf::Texture* map_texture) {
        
        loadMap(mapFilePath);  // carrega arquivo json
        this->entitys = entitys; // referencia para o map de entitys da FaseState
        
        // .json tenha o mesmo nome do .png e ambos estejam na mesma pasta

        this->map_texture = map_texture; // referencia para a textura do mapa da FaseState
        map_texture->loadFromFile(mapFilePath.substr(0, mapFilePath.find_last_of(".")) + ".png");

        // Pega as informações do mapa

        int sizeTiled = map["tilewidth"];
        int width = map["width"];
        int height = map["height"];
        
        int index = 0;

        //Loop para criar as entitys 0 = vazio, -1 = jogador e outros valores são entitys diversas
    
        /*for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int tileId = map["layers"][0]["data"][index++];
                if(tileId != 0){
                    sf::Vector2f pos(x * sizeTiled, y * sizeTiled);
                    sf::Vector2f size(sizeTiled, sizeTiled);
                    entitys->push_back(createEntity(pos, size, tileId));
                }
            }
        }*/



        // Loop para criar a fase, mas agora com Entity de sizes diversos;

        /*for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                long long int tileId = map["layers"][0]["data"][index];
                if(tileId != 0){
                    int mult = 1;
                    while(tileId == map["layers"][0]["data"][++index]){
                        mult++;
                    }
                    sf::Vector2f pos(x*sizeTiled, y*sizeTiled);
                    x += mult - 1;

                    sf::Vector2f size(sizeTiled*mult, sizeTiled);
                    Entity* entity = createEntity(pos, size, tileId);
                    (*entitys)[entity->getType()] = entity;
                
                }else
                    index++;
            }
        }*/


    for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (index >= map["layers"][0]["data"].size()) {
                    // Verifique se o índice está dentro dos limites
                    break;
                }

                long long int tileId = map["layers"][0]["data"][index];
                if (tileId != 0) {
                    int mult = 1;
                    while (index + 1 < map["layers"][0]["data"].size() && tileId == map["layers"][0]["data"][index + 1] && x + mult < width) {
                        mult++;
                        index++;
                    }
                    sf::Vector2f pos(x * sizeTiled, y * sizeTiled);
                    x += mult - 1;

                    sf::Vector2f size(sizeTiled * mult, sizeTiled);
                    Entitys::Entity* entity = createEntity(pos, size, tileId);
                    entitys->insert(std::make_pair(entity->getType(), entity));
                }
                index++;
            }
        }
    }

    Entitys::Entity* Tilemap::createEntity(sf::Vector2f pos, sf::Vector2f size, int type) {
        if (type == -1) {
            return new Entitys::Characters::Players::Player(pos, size, q);
        }
        else {
            return new Entitys::Platform(pos, size, q);
        }
    }

    nlohmann::json Tilemap::getMap()
    {
        return map;
    }
}