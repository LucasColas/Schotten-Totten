//
// Created by lucas on 06/05/2023.
//
#include "Combinaison.h"
#include "Carte.h"
#include "Borne.h"

#ifndef SCHOTTEN_TOTTEN_REVENDICATION_H
#define SCHOTTEN_TOTTEN_REVENDICATION_H
//Revendication sera un attribut dans Jeu.
class Revendication {
private:
    Combinaison* combinaison_joueur1;
    Combinaison* combinaison_joueur2;
    bool max_cartes_pose;
    int nb_cartes_max;
    int historique;
    vector<int> regles;
    vector<Carte*> cartes_joueur1;
    vector<Carte*> cartes_joueur2;
    int joueur1, joueur2;
    vector<Combinaison*> combinaisons;
    vector<Carte*> cartes;
    static map<string,int> rank;
public:
    Revendication(Borne* b);
    void MeilleureCombinaison(); //Donne la meilleure combinaison qu'on a parmis un ensemble de cartes
    bool PotentielleCombinaison(vector<Borne*>& bornes, vector<Carte*>& cartes, Combinaison* combinaison, vector<Carte*>& cartes_aversaire); //Nous renvoie vraie si l'adversaire peut avoir une meilleure combinaison
    int Revendiquant_avec_max_cartes(); //Joueur qui obtient la borne. 0 si ce n'est aucun des joueurs.
    void generer_combi(vector<Carte*>& cartes_adversaire, vector<Carte*>& cartes);

    int Revendiquant();
    int Revendiquer_sans_max_cartes(vector<Carte*>& cartes, vector<Borne*>& bornes);

    int Revendiquer(); //Méthode qui teste les différents cas de revendications et renvoie le joueur qui peut revendiquer la borne. 0 sinon.

};
#endif //SCHOTTEN_TOTTEN_REVENDICATION_H
