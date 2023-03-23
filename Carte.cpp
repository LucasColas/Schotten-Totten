//
// Created by lucas on 23/03/2023.
//
#include "Carte.h"
Carte_clan::Carte_clan(string id_, Couleur couleur_, int force_) {
    id = id_;
    couleur = couleur_;
    force = force_;
}

Couleur Carte_clan::get_couleur() {
    return couleur;
}

int Carte_clan::get_force() {
    return force;
}