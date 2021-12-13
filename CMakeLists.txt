cmake_minimum_required(VERSION 3.20)
project(final_fantasy___reclaim_your_throne)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)
include_directories(src/header/model)
include_directories(src/header/model/Objet)
include_directories(src/header/model/Personnage)
include_directories(src/header/model/Piece)
include_directories(src/header/model/Action)

add_executable(final_fantasy___reclaim_your_throne
        src/header/model/Action/Action.h
        src/header/model/Objet/Consommable.h
        src/header/model/Objet/Equipement.h
        src/header/model/Objet/Objet.h
        src/header/model/Personnage/Amazone.h
        src/header/model/Personnage/Guerrier.h
        src/header/model/Personnage/Moine.h
        src/header/model/Personnage/Personnage.h
        src/header/model/Personnage/PersonnageFactory.h
        src/header/model/Personnage/Sorcier.h
        src/header/model/Piece/Map.h
        src/header/model/Piece/Piece.h
        src/implem/model/Action/Action.cpp
        src/implem/model/Objet/Consommable.cpp
        src/implem/model/Objet/Equipement.cpp
        src/implem/model/Objet/Objet.cpp
        src/implem/model/Personnage/Amazone.cpp
        src/implem/model/Personnage/Guerrier.cpp
        src/implem/model/Personnage/Moine.cpp
        src/implem/model/Personnage/Personnage.cpp
        src/implem/model/Personnage/PersonnageFactory.cpp
        src/implem/model/Personnage/Sorcier.cpp
        src/implem/model/Piece/Map.cpp
        src/implem/model/Piece/Piece.cpp
        src/main.cpp src/header/model/Joueur/Joueur.h src/implem/model/Joueur/Joueur.cpp)
