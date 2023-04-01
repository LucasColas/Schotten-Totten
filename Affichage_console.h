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
    void affichage_bornes(vector<Borne*>& Bornes);
    void affichage_cartes();
    void affichage_pioche();
    void affichage_pioche_tactique();
    void affichage_défausse();
    int positionner_carte();

};
#endif //SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
