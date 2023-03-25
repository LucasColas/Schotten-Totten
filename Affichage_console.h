//
// Created by lucas on 25/03/2023.
//
#include <string>

using namespace std;
#ifndef SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
#define SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
class Affichage_console {
    string edition;
public:
    Affichage_console();
    void affichage_borne();
    void affichage_cartes();
    void affichage_pioche();
    void affichage_pioche_tactique();
    void affichage_défausse();
    int positionner_carte();




};
#endif //SCHOTTEN_TOTTEN_AFFICHAGE_CONSOLE_H
