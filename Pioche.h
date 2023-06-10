//
// Created by lucas on 09/04/2023.
//

#ifndef SCHOTTEN_TOTTEN_PIOCHE_H
#define SCHOTTEN_TOTTEN_PIOCHE_H
#include "Carte.h"
#include "Schotten_Totten.h"
#include <iostream>
#include <vector>
class Pioche {

private:
    vector<Carte*> cartes_pioche;
    string id;

public:
    Pioche(vector<Carte_clan*>& cartes);
    Pioche(vector<Carte_tactique*>& cartes);
    Pioche(int n);
    void melange();
    Carte& piocher_carte();
    bool est_vide();
    int sizePioche() const {return cartes_pioche.size();};
    void ajout_carte(Carte* carte) {cartes_pioche.push_back(carte);};
};
#endif //SCHOTTEN_TOTTEN_PIOCHE_H
