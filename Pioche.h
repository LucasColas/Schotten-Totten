//
// Created by lucas on 24/03/2023.
//


#ifndef SCHOTTEN_TOTTEN_PIOCHE_H
#define SCHOTTEN_TOTTEN_PIOCHE_H
#include "Carte.h"
#include "Schotten_Totten.h"
class Pioche {

private:
    deque<Carte*> pioche;

public:
    Pioche(const Schotten_Totten& S);
    void melange();
    Carte& piocher_carte();
    bool est_vide();
};
#endif //SCHOTTEN_TOTTEN_PIOCHE_H
