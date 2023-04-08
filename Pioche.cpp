//
// Created by lucas on 24/03/2023.
//
#include "Pioche.h"
#include "Carte.h"
using namespace std;

Pioche::Pioche(const Schotten_Totten& S) {
    for (int i = 0; S.getNb_Cartes_clan(); i ++) {
        pioche.push_back(&S.getCarte_clan(i));
    }

}
bool Pioche::est_vide() {
    return pioche.size() == 0;
}
Carte& Pioche::piocher_carte() {
    if (est_vide()) {
        throw "pas possible de piocher. Pioche vide";
    }

    Carte& c = *pioche[pioche.size() - 1];
    pioche.pop_back();
    return c;
}

