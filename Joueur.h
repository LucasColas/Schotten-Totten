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
    bool ia;
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
    string& getNom() {return nom;};
    int choix_borne();
    void ajout_carte(Carte* c);
    void setNbPoints(int pts);
    int getNbCartes() {return cartes.size();};
    int getNbTactiqueJouees() const {return nb_cartes_tactiques_jouees;};
    void carteTactiqueJouee() {nb_cartes_tactiques_jouees++;};
    vector<Carte*>& getCartes() {return cartes;};
    void supprimerCarte(int i);
    bool getIa() const {return ia;};


};

class IA : public Joueur {

public:
    IA(string n, int nb_cartes, int nb_tactiques_jouees=0, int joker_j = 0, int nb_p=0, int nb_b=9);
    Carte& choix_carte(); // Choisi une carte dans la main de l'IA
    int choix_borne(); // Choisi une borne pour l'IA
    static int choix_entier(const int min, const int max); // Fais un choix aleatoire entre min et max compris
};
#endif //SCHOTTEN_TOTTEN_JOUEUR_H
