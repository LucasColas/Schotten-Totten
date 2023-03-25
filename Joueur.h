//
// Created by lucas on 24/03/2023.
//
#include "Carte.h"
#include <string>

using namespace std;
#ifndef SCHOTTEN_TOTTEN_JOUEUR_H
#define SCHOTTEN_TOTTEN_JOUEUR_H
class Joueur {
protected:
    string nom;
    int nb_bornes;
    vector<Carte> cartes;
    int nb_max_cartes;
    int nb_cartes_tactiques_jouees;
    int joker_joue;
    int nb_points;
public:
    Joueur();
    void choix_position();


};

class IA : Joueur {

};
#endif //SCHOTTEN_TOTTEN_JOUEUR_H
