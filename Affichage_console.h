//
// Created by lucas on 25/03/2023.
//
#include <string>
#include "Carte.h"
#include "defausse.h"
#include "Borne.h"
using namespace std;
#ifndef SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
#define SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
class Affichage_console {
    string variante;
public:

    Affichage_console(string v);
    void Afficher_jeu(vector<Borne*>& Bornes, int joueur_actuelle);
    void Afficher_proposition();
    void afficher_bornes(vector<Borne*>& Bornes);
    void afficher_cartes_bornes(vector<Borne*>& Bornes, int joueur_actuelle);

    void afficher_défausse(const Defausse& d);
    void afficher_cartes_joueur(vector<Carte*>& cartes);
    void choix_pioche();


};
#endif //SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
