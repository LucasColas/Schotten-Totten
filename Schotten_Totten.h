//
// Created by lucas on 24/03/2023.
//
#include <string>
#include "Carte.h"
#include "Joueur.h"
#include "Pioche.h"
#include "Affichage_console.h"
#include <cstddef>
using namespace std;

#ifndef SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
#define SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
class Schotten_Totten {
private:

    vector<Borne*> bornes;
    vector<Carte_clan*> cartes;
    int nb_Cartes_clan;
    int nb_bornes;

public:
    Schotten_Totten();
    void gagnant();
    void calcul_score_borne();
    void revendication();
    int getNb_bornes() const { return nb_bornes;};
    int getNb_Cartes_clan() const {return nb_Cartes_clan;};

    Carte_clan& getCarte_clan(int i) const {
        if (i >= nb_Cartes_clan) {
            throw SetException("La carte est invalide");
        }

        return *cartes[i];
    }
    Borne& getBorne(int i) const {
        if (i >= nb_bornes) throw SetException("la borne est invalide");
        return *bornes[i];
    }



};

class Tactique : Schotten_Totten {
private:
    Pioche pioche_tactique;
    Pioche défausse;
    vector<Carte_tactique*> cartes_tactique;

public:
    Tactique();

};

#endif //SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
