//
// Created by lucas on 25/03/2023.
//
using namespace std;

#include <stack>
#include "Carte.h"
#ifndef SCHOTTEN_TOTTEN_DEFAUSSE_H
#define SCHOTTEN_TOTTEN_DEFAUSSE_H
class Defausse {
private:
    vector<Carte*> defausse;
public:
    //void consulter();
    void ajout_defausse(Carte* c);
    bool estVide() const {return defausse.empty();};
    size_t getNbCartes() const { return defausse.size();};
    Carte& getCarte(size_t i) const {return *defausse[i];};
};
#endif //SCHOTTEN_TOTTEN_DEFAUSSE_H
