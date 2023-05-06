//
// Created by lucas on 06/05/2023.
//
#include "Combinaison.h"
#include "Carte.h"
#ifndef SCHOTTEN_TOTTEN_REVENDICATION_H
#define SCHOTTEN_TOTTEN_REVENDICATION_H
//Revendication sera un attribut dans Jeu.
class Revendication {
private:
    Combinaison* combinaison_joueur1;
    Combinaison* combinaison_joueur2;
    bool max_cartes_pose;
    int historique;
    vector<int> regles;
    vector<Carte*> cartes_joueur1;
    vector<Carte*> cartes_joueur2;
public:
    Revendication(vector<Carte*>& cartes_joueur1_, vector<Carte*>& cartes_joueur2_, bool max_cartes_pose_, int h, vector<int>& r);
    void MeilleureCombinaison(); //Donne la meilleure combinaison qu'on a parmis un ensemble de cartes
    bool PotentielleCombinaison(); //Nous renvoie vraie si l'adversaire peut avoir une meilleure combinaison
    int Revendiquant_avec_max_cartes(); //Joueur qui obtient la borne. 0 si ce n'est aucun des joueurs.

    int Revendiquant();

    int Revendiquer();

};
#endif //SCHOTTEN_TOTTEN_REVENDICATION_H
