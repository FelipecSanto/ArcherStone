#cmake_minimum_required(VERSION 3.12)
#project(main)
#add_executable(${PROJECT_NAME})
#target_sources(${PROJECT_NAME} PRIVATE main.cpp)
#include(FetchContent)
#FetchContent_Declare(sfml
#    GIT_REPOSITORY https://github.com/SFML/SFML.git
#    GIT_TAG 2.6.x
#)
#FetchContent_MakeAvailable(sfml)

#target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)



cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_MAKE_PROGRAM C:/VScode/bin/make.exe)

# Adicione todos os arquivos .cpp e .h ao seu executável
add_executable(${PROJECT_NAME} main.cpp)
target_sources(${PROJECT_NAME} PRIVATE 
    Managers/StateManager.h
    Managers/StateManager.cpp
    Managers/GraphicsManager.h
    Managers/GraphicsManager.cpp
    Managers/CollisionManager.h
    Managers/CollisionManager.cpp
    GraphicsElements/Button.h
    GraphicsElements/Button.cpp
    States/State.h
    States/Fases/GameState.h
    States/Fases/GameState.cpp
    States/Fases/FaseState.h
    States/Fases/FaseState.cpp
    States/Menus/MenuInicialState.h
    States/Menus/MenuInicialState.cpp
    States/Menus/MenuPauseState.h
    States/Menus/MenuPauseState.cpp
    States/Menus/MenuOptionsState.h
    States/Menus/MenuOptionsState.cpp
    States/Menus/MenuRankingState.h
    States/Menus/MenuRankingState.cpp
    States/Menus/MenuState.h
    States/Menus/MenuState.cpp
    Entitys/Entity.h
    Entitys/Entity.cpp
    Entitys/Platform.h
    Entitys/Platform.cpp
    Entitys/Characters/Character.h
    Entitys/Characters/Character.cpp
    Entitys/Characters/Player.h
    Entitys/Characters/Player.cpp
    Mapa/QuadTree.h
    Mapa/QuadTree.cpp
    Mapa/tilemap.h
    Mapa/tilemap.cpp
    nlohmann/json.hpp
    nlohmann/json_fwd.hpp
)

include(FetchContent)
FetchContent_Declare(sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(sfml)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)