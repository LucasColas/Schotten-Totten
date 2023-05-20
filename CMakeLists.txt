cmake_minimum_required(VERSION 3.24)
project(Schotten_Totten)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C://Qt//6.5.0//mingw_64//lib//cmake")

# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt6Widgets REQUIRED)

add_executable(Schotten_Totten main.cpp Carte.cpp Carte.h Joueur.cpp Joueur.h Jeu.cpp Jeu.h Schotten_Totten.cpp Schotten_Totten.h Affichage_console.cpp Affichage_console.h defausse.cpp defausse.h Jeu_cartes.cpp Jeu_cartes.h Factory.cpp Factory.h Pioche.cpp Pioche.h set.cpp set.h Combinaison.h Combinaison.cpp Borne.cpp Revendication.h Revendication.cpp vuepartie.cpp vuepartie.h vuecarte.cpp vuecarte.h)

QT6_WRAP_CPP(MOC_SOURCES ${Q_OBJECT_HEADERS})
target_link_libraries(Schotten_Totten Qt6::Widgets)