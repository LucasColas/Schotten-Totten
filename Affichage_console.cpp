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

void Affichage_console::afficher_cartes_joueur_haut(vector<Borne *> &Bornes, int joueur) {
    int espace = 0;
    int max_cartes = 0;


    for (int i = 0; i < Bornes.size(); i++) {
        if (joueur == 1) {
            if (Bornes[i]->getCartes_joueur_1().size() > max_cartes) {
                max_cartes = Bornes[i]->getCartes_joueur_1().size();
            }
        }

        else {
            if (Bornes[i]->getCartes_joueur_2().size() > max_cartes) {
                max_cartes = Bornes[i]->getCartes_joueur_2().size();
            }
        }

    }
    for (int j = max_cartes - 1; j >= 0; j--) {
        for (int i = 0; i < Bornes.size(); i++) {
            for (int k = 0; k < espace; k++) {
                cout << " " << flush;
            }
            if (joueur == 1){
                if (Bornes[i]->getCartes_joueur_1().size() >= max_cartes) {
                    cout << Bornes[i]->getCartes_joueur_1()[j] << flush;
                }
                else {
                    cout << "___" << flush;
                }
            }

            else {
                if (Bornes[i]->getCartes_joueur_2().size() >= max_cartes) {
                    cout << Bornes[i]->getCartes_joueur_2()[j] << flush;
                }
                else {
                    cout << "___" << flush;
                }
            }


            espace += 3;

            cout << endl;
        }
        espace = 0;
    }


}

void Affichage_console::afficher_bornes(vector<Borne *> &Bornes) {
    for (int i = 0; i < Bornes.size(); i++) {
        cout << Bornes[i];
    }
}
