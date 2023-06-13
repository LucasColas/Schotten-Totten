//
// Created by lucas on 25/03/2023.
//
#include <iostream>
#include "defausse.h"
#include "Carte.h"
#include <vector>

using namespace std;
Defausse::Defausse() {
    cout << "instance de defausse" << endl;
}
void Defausse::ajout_defausse(Carte* c) {
    defausse.push_back(c);
}

