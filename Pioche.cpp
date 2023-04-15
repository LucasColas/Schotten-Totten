//
// Created by lucas on 09/04/2023.
//
#include "Pioche.h"
#include "Carte.h"
#include "Schotten_Totten.h"
#include <iostream>
using namespace std;
Pioche::Pioche(vector<Carte_clan*>& cartes) {
    for (size_t i = 0; i < cartes.size(); i++) {
        cartes_pioche.push_back(cartes[i]);
    }
}

Pioche::Pioche(vector<Carte_tactique*>& cartes) {
    for (size_t i = 0; i < cartes.size(); i++) {
        cartes_pioche.push_back(cartes[i]);
    }
}
Pioche::Pioche(int n) {
    cout << "essai";
}
bool Pioche::est_vide() {
    return cartes_pioche.size() == 0;
}
Carte& Pioche::piocher_carte() {
    if (est_vide()) {
        throw "pas possible de piocher. Pioche vide";
    }

    Carte& c = *cartes_pioche.back();
    cartes_pioche.pop_back();
    cout << "return c" << endl;
    //cout << c << endl;
    return c;
}