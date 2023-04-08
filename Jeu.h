//
// Created by lucas on 24/03/2023.
//
#include "Joueur.h"
#include "Affichage_console.h"
#include "Schotten_Totten.h"
using namespace std;
#ifndef SCHOTTEN_TOTTEN_JEU_H
#define SCHOTTEN_TOTTEN_JEU_H
class Jeu {
private:
    int nb_joueurs;
    int joueur_actuelle;
    vector<Joueur*> joueurs;
    string mode_jeu;
    string variante;
    vector<string> editions;
    int nb_parties;
    int nb_parties_jouees;
    int nb_joueurs_humains;
    string choix_IA;
    string choix_affichage;
    Affichage_console* affichageConsole;

    Schotten_Totten* schottenTotten;
    map<string, Pioche*> pioches;

public:

    Jeu(string mode,string v);
    void designe_premier_joueur();
    void setNb_joueurs_humains();
    void choix_jeu();
    void joueur_tour();
    void setAffichage(string affichage);
    void setChoix_IA();
    void creation_joueurs();
    void setNb_parties();
    void resume();
    void distribution_cartes();
    int partie_terminee();
    string getModeJeu() const {return mode_jeu;};
    string getVariante() const { return variante;};
    int getNbParties() const { return nb_parties;};
    int getNbPartiesJouees() const { return nb_parties_jouees;};
    void setPioches();

};
#endif //SCHOTTEN_TOTTEN_JEU_H
