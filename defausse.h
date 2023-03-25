//
// Created by lucas on 25/03/2023.
//
using namespace std;

#include <stack>
#include "Carte.h"
#ifndef SCHOTTEN_TOTTEN_DEFAUSSE_H
#define SCHOTTEN_TOTTEN_DEFAUSSE_H
class defausse {
private:
    stack<Carte_tactique*> defausse;
public:
    void consulter();
    void ajout_defausse();
};
#endif //SCHOTTEN_TOTTEN_DEFAUSSE_H
