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
    vector<Carte*> cartes;
    int nb_max_cartes;
    int nb_cartes_tactiques_jouees;
    int joker_joue;
    int nb_points;
public:
    Joueur(string n, int nb_cartes, int nb_tactiques_jouees=0, int joker_j = 0, int nb_p=0, int nb_b=9);
    Carte& choix_carte();
    int choix_borne();
    void ajout_carte(Carte* c);


};

class IA : Joueur {

};
#endif //SCHOTTEN_TOTTEN_JOUEUR_H
