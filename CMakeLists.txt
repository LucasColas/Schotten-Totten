cmake_minimum_required(VERSION 3.24)
project(Schotten_Totten)

set(CMAKE_CXX_STANDARD 17)

add_executable(Schotten_Totten main.cpp Carte.cpp Carte.h Joueur.cpp Joueur.h Jeu.cpp Jeu.h Schotten_Totten.cpp Schotten_Totten.h Affichage_console.cpp Affichage_console.h defausse.cpp defausse.h Jeu_cartes.cpp Jeu_cartes.h Factory.cpp Factory.h Pioche.cpp Pioche.h set.cpp set.h)
