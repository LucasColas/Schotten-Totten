//
// Created by lucas on 24/03/2023.
//

#include <iostream>

#include "Jeu.h"
#include "Schotten_Totten.h"
using namespace std;


Jeu::Jeu(string mode, string v) {

    mode_jeu = mode;
    variante = v;
    nb_parties_jouees = 0;

    setNb_parties();
    choix_jeu();

}

void Jeu::setNb_parties() {
    cout << "Nombre de parties : " << endl;
    cin >> nb_parties;
    cout << "Nombre de parties qui sera joue : " << nb_parties << endl;

}

void Jeu::choix_jeu() {
    if (mode_jeu.compare("Schotten Totten") == 0) {
        if (variante.compare("normal") == 0) {
            cout << "Schotten Totten normal " << endl;
            schottenTotten = new Schotten_Totten();

        }
        else {
            cout << "Schotten Totten tactique " << endl;
            schottenTotten = new Schotten_Totten();
        }
    }
    affichageConsole = new Affichage_console(variante);
    for (int i = 0; i < schottenTotten->getNb_Cartes_clan(); i++) {
        cout << schottenTotten->getCarte_clan(i) << endl;
        cout << i << endl;
    }
}