//
// Created by lucas on 09/04/2023.
//
#include "Pioche.h"
#include "Carte.h"
#include "Schotten_Totten.h"
#include <iostream>
#include <algorithm>
#include <random>


using namespace std;
Pioche::Pioche(vector<Carte_clan*>& cartes) {
    for (size_t i = 0; i < cartes.size(); i++) {
        cartes_pioche.push_back(cartes[i]);
    }
    melange();
}

Pioche::Pioche(vector<Carte_tactique*>& cartes) {
    for (size_t i = 0; i < cartes.size(); i++) {
        cartes_pioche.push_back(cartes[i]);
    }
    melange();


}

void Pioche::melange() {
    random_device rd;
    mt19937 g(rd());

    // Melange du vecteur avec le seed
    shuffle(cartes_pioche.begin(), cartes_pioche.end(), g);
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