//
// Created by lucas on 24/03/2023.
//
#include <string>
#include "Carte.h"
#include "Joueur.h"
#include "Pioche.h"

using namespace std;

#ifndef SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
#define SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
class Schotten_Totten {
private:
    string choix_affichage;
    Pioche pioche;
    vector<Borne*> bornes;
public:
    Schotten_Totten(string affichage); //indique l'affichage et créer la pioche
    void gagnant();
    void calcul_score_borne();
    void revendication();

};

class Tactique : Schotten_Totten {
private:
    Pioche pioche_tactique;
    Pioche défausse;

public:
};

#endif //SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
