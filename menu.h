//
// Created by lucas on 28/05/2023.
//

#ifndef SCHOTTEN_TOTTEN_MENU_H
#define SCHOTTEN_TOTTEN_MENU_H
#include "Jeu.h"
class Menu {
private:
    Jeu* jeu;
    string mode_jeu;
    string variante;
    int choix_jeu, choix_variante;
    int nb_parties, nb_joueurs_humains,nb_max_joueurs;
    vector<string> joueurs;

public:
    Menu();
    void SetNbParties();
    void setJoueurs();
    void jouer();

};
#endif //SCHOTTEN_TOTTEN_MENU_H
