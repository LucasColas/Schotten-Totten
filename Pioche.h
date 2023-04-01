//
// Created by lucas on 24/03/2023.
//
#include "Carte.h"
#ifndef SCHOTTEN_TOTTEN_PIOCHE_H
#define SCHOTTEN_TOTTEN_PIOCHE_H
class Pioche {

private:
    deque<Carte*> pioche;

public:
    Pioche();
    void melange();
    Carte piocher_carte();
};
#endif //SCHOTTEN_TOTTEN_PIOCHE_H
