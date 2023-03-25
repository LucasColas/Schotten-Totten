//
// Created by lucas on 24/03/2023.
//
#include "Joueur.h"
using namespace std;
#ifndef SCHOTTEN_TOTTEN_JEU_H
#define SCHOTTEN_TOTTEN_JEU_H
class Jeu {
private:
    int nb_joueurs;
    int joueur_actuelle;
    vector<Joueur> joueurs;
    string edition;
    vector<string> editions;
    int nb_parties;
    int nb_joueurs_humain;
    string choix_IA;
    string choix_affichage;
public:

    Jeu();
    void designe_premier_joueur();
    void choix_mode_jeu();
    void choix_variante();
    void joueur_tour();
    void setAffichage();
    void setChoix_IA();
};
#endif //SCHOTTEN_TOTTEN_JEU_H
