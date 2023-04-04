//
// Created by lucas on 25/03/2023.
//
#include <string>
#include "Carte.h"
using namespace std;
#ifndef SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
#define SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
class Affichage_console {
    string variante;
public:

    Affichage_console(string v);

    void afficher_bornes(vector<Borne*>& Bornes);
    void afficher_cartes_joueur1(vector<Borne*>& Bornes);
    void afficher_cartes_joueur2();
    void afficher_cartes_joueur_actuel();
    void afficher_pioche();
    void afficher_pioche_tactique();
    void afficher_défausse();
    int positionner_carte();

};
#endif //SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
