//
// Created by lucas on 24/03/2023.
//


using namespace std;

#ifndef SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
#define SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
#include <string>

#include <cstddef>
#include "Carte.h"
class Schotten_Totten {
    friend class Jeu;
protected:

    vector<Borne*> bornes;
    vector<Carte_clan*> cartes;
    int nb_Cartes_clan;
    int nb_bornes;
    int nb_cartes_par_joueur;


public:
    Schotten_Totten();
    void gagnant();
    void calcul_score_borne();
    void revendication();
    int getNb_bornes() const { return nb_bornes;};
    int getNb_Cartes_clan() const {return nb_Cartes_clan;};
    virtual vector<Carte_tactique*>& getCartesTactique() {
        throw SetException("La classe Schotten_Totten n'a pas de cartes tactiques");

    }

    vector<Carte_clan*>& getCartesClan() {
        return cartes;
    }

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

    int getNb_Cartes_par_joueur() const { return nb_cartes_par_joueur;};



};

class Tactique : public Schotten_Totten{
    friend class Jeu;
private:
    vector<string> types;

    vector<Carte_tactique*> cartes_tactique;
    int nb_cartes_tactiques;
    vector<Carte_tactique*>& getCartesTactique() override {
        return cartes_tactique;
    }

public:
    Tactique();
    void test();

};

#endif //SCHOTTEN_TOTTEN_SCHOTTEN_TOTTEN_H
