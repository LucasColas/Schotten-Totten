//
// Created by lucas on 23/03/2023.
//
#include "Carte.h"
#include "iostream"

string toString(Couleur c) {
    switch (c) {
        case Couleur::Rouge: return "R";
        case Couleur::Vert: return "V";
        case Couleur::Bleu: return "B";
        case Couleur::Marron: return "M";
        case Couleur::Dore: return "D";
        case Couleur::Violet: return "Vi";
        case Couleur::NC: return "NC";
        default: throw SetException("Couleur inconnue");
    }
}

ostream& operator<<(ostream& f, Couleur c) {
    f << toString(c);
    return f;
}
Carte_clan::Carte_clan(string id_, Couleur couleur_, int force_) {
    id = id_;
    couleur = couleur_;
    force = force_;
}

Borne::Borne(string id_, int r, int nb_cartes, int possesseur) {
    id = id_;
    regle = r;
}

Carte_tactique::Carte_tactique(string id_, string t) {
    id = id_;
    type = t;
}

Carte_Elite::Carte_Elite(string id_, string t, int f, Couleur c) : Carte_tactique(id_, t) {
    id = id_;
    type = t;
    force = f;
    couleur = c;
}



ostream& operator<<(ostream& f, const Carte_clan& c) {
    f << c.get_force() << "," << c.get_couleur();
    return f;
}

ostream& operator<<(ostream& f, const Borne& b) {
    f << b.getRegle() << "\n" << b.GetPossesseur() << "\n" << b.getNbMaxCartes();
    return f;
}