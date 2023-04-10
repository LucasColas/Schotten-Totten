//
// Created by lucas on 09/04/2023.
//
#include "Pioche.h"
#include "Carte.h"
#include "Schotten_Totten.h"
#include <iostream>
using namespace std;
Pioche::Pioche(Schotten_Totten& j): cartes(new const Carte*[j.getNb_Cartes_clan()]), nb(j.getNb_Cartes_clan()) {
    for(size_t i=0; i <nb; i++)
        cartes[i] = &j.getCarte_clan(i);
}
Pioche::Pioche(int n) {
    cout << "essai";
}
bool Pioche::est_vide() {
    return nb == 0;
}
Carte& Pioche::piocher_carte() {
    if (est_vide()) {
        throw "pas possible de piocher. Pioche vide";
    }

    Carte& c = *cartes[nb- 1];
    nb--;
    return c;
}