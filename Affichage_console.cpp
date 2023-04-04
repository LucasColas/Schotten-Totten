//
// Created by lucas on 25/03/2023.
//
#include "Affichage_console.h"
#include "Carte.h"
#include <iostream>
using namespace std;

Affichage_console::Affichage_console(string v) {
    variante = v;

}

void Affichage_console::afficher_cartes_joueur1(vector<Borne *> &Bornes) {
    int espace = 0;
    int max_cartes = 0;
    for (int i = 0; i < Bornes.size(); i++) {
        if (Bornes[i]->getCartes_joueur_1().size() > max_cartes) {
            max_cartes = Bornes[i]->getCartes_joueur_1().size();
        }
    }
    for (int j = max_cartes - 1; j >= 0; j--) {
        for (int i = 0; i < Bornes.size(); i++) {
            for (int k = 0; k < espace; k++) {
                cout << " " << flush;
            }
            if (Bornes[i]->getCartes_joueur_1().size() >= max_cartes) {
                cout << Bornes[i]->getCartes_joueur_1()[j] << flush;
            }
            else {
                cout << "   " << flush;
            }

            espace += 4;

            cout << endl;
        }
        espace = 0;
    }


}
