//
// Created by lucas on 06/05/2023.
//
#include "Carte.h"
#include "iostream"
#include "Combinaison.h"
#ifndef SCHOTTEN_TOTTEN_BORNE_H
#define SCHOTTEN_TOTTEN_BORNE_H

class Borne {

private:
    vector<int> regles;
    int nb_max_cartes;
    int possesseur;
    vector<Carte*> cartes_joueur_1;
    vector<Carte*> cartes_joueur_2;
    vector<Carte*> carte_dessus;
    Combinaison* combinaison_joueur_1;
    Combinaison* combinaison_joueur_2;
    string id;
    //pour savoir qui a posé la troisième ou quatrième carte en premier. On met 1 si c'est le joueur 1. 2 sinon.
    int historique;
public:
    Borne(string id_, int r=0, int nb_cartes=3, int p=0);
    vector<int> getRegles() const { return regles;};
    bool ajoutRegle(int r);
    int getNbMaxCartes() const { return nb_max_cartes;};
    int GetPossesseur() const {return possesseur;};
    void setPossesseur(int joueur);
    vector<Carte*> getCartes_joueur_1() {return cartes_joueur_1;};
    vector<Carte*> getCartes_joueur_2() {return cartes_joueur_2;};
    Carte& supprimer_carte(int joueur, int num);
    bool ajout_Carte(Carte* c, int joueur_actuelle);
    string getId() const {return id;};
    bool possible_revendication();
    void revendication(int joueur_actuel);
    void demander_valeurs(int joueur_actuel);
    bool revendication_faite();
    void creerCombinaison_joueur1();
    void creerCombinaison_joueur2();
    Combinaison& getCombinaisonJoueur1() const {return *combinaison_joueur_1;};
    Combinaison& getCombinaisonJoueur2() const {return *combinaison_joueur_2;};
    int getHistorique() const {return historique;};

    friend ostream& operator<<(ostream& f, const Borne& b);
};
#endif //SCHOTTEN_TOTTEN_BORNE_H
