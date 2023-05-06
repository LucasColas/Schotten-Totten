//
// Created by lucas on 23/03/2023.
//
#include "Carte.h"
#include "iostream"


string toString(Couleur c) {
    switch (c) {
        case Couleur::Rouge: return "Ro";
        case Couleur::Vert: return "Ve";
        case Couleur::Bleu: return "Bl";
        case Couleur::Marron: return "Ma";
        case Couleur::Dore: return "Do";
        case Couleur::Violet: return "Vi";
        case Couleur::NC: return "NC";
        default: throw SetException("Couleur inconnue");
    }
}


ostream& operator<<(ostream& f, Couleur c) {
    f << toString(c);
    return f;
}
Carte_clan::Carte_clan(string id_, Couleur couleur_, int force_, string t) {
    id = id_;
    couleur = couleur_;
    force = force_;
    type = t;
}





Carte_tactique::Carte_tactique(string id_, string t) {
    id = id_;
    type = t;
}

bool Carte_Elite::setCouleur() {
    cout << "choisissez la couleur que vous voulez pour cette carte elite" << endl;
    int choix;
    int i = 1;
    int index = 0;
    for (auto c: couleurs_possibles) {
        cout << to_string(i) << " : " << toString(c) << endl;
        i++;
    }
    cout << "votre choix : ";
    cin >> choix;
    if (choix < 1 || choix > couleurs_possibles.size()) {
        cout << "choix invalide" << endl;
        return false;
    }
    for (auto c : couleurs_possibles) {
        if (index == choix-1) {
            couleur = c;
        }
        index++;
    }
    return true;

}

bool Carte_Elite::setForce() {
    cout << "choisissez la force que vous voulez parmi les forces possibles" << endl;
    int i = 1;
    int choix;
    for (auto f : forces_possibles) {
        cout << to_string(i) << " : " << to_string(f) << endl;
        i++;
    }
    cout << "votre choix : ";
    cin >> choix;
    if (choix < 1 || choix > forces_possibles.size()) {
        cout << "erreur choix";
        return false;
    }
    force = forces_possibles[choix-1];

    return true;
}
Carte_Elite::Carte_Elite(string t, string id_, int f, Couleur c) : Carte_tactique(id_, t) {
    //id = id_;
    //type = t;
    force = f;
    couleur = c;

    couleurs_possibles = {Couleur::Rouge, Couleur::Bleu, Couleur::Dore, Couleur::Marron, Couleur::Vert, Couleur::Violet};
    if (id == "Porte-Bouclier") {
        //couleurs_possibles = {Couleur::Rouge, Couleur::Bleu, Couleur::Dore, Couleur::Marron, Couleur::Vert, Couleur::Violet};
        for (int i = 1; i < 4; i++) {
            forces_possibles.push_back(i);
        }
    }
    if (id == "Espion") {
        //couleurs_possibles = {Couleur::Rouge, Couleur::Bleu, Couleur::Dore, Couleur::Marron, Couleur::Vert, Couleur::Violet};
    }

    if (id.find("Joker") != string::npos) {
        //couleurs_possibles = {Couleur::Rouge, Couleur::Bleu, Couleur::Dore, Couleur::Marron, Couleur::Vert, Couleur::Violet};
        for (int i = 1; i < 10; i++) {
            forces_possibles.push_back(i);
        }
    }
}

Carte_Combat::Carte_Combat(string t, string id_, int r) : Carte_tactique(id_, t) {
    regle = r;

}

Carte_Ruse::Carte_Ruse(string t, string id_) : Carte_tactique(id_, t){

}

Carte_chasseur_de_tete::Carte_chasseur_de_tete(string t, string id_, int nb) : Carte_Ruse(t, id_){
    nb_cartes = nb;
}

void Carte_chasseur_de_tete::proposition() {
    cout << "Les choix : " << endl;
    cout << "1. Piochez trois cartes d'une pioche" << endl;
    cout << "2. Piochez trois cartes de deux pioches" << endl;
    cout << "Choisissez ce que vous voulez faire (entrez 1 ou 2):" << endl;
}



Carte_Stratege::Carte_Stratege(string t, string id_) : Carte_Ruse(t, id_){

}

ostream& operator<<(ostream& f, const Carte& c) {
    if (c.getType() == "Clan") {
        f << c.get_force() << "," << c.get_couleur();
    }
    else {
        f << c.getId().substr(0, 4);
    }

    return f;
}
ostream& operator<<(ostream& f, const Carte_clan& c) {
    cout << "call " << endl;
    f << c.get_force() << "," << c.get_couleur();
    return f;
}


ostream& operator<<(ostream& f, const Carte_tactique& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}

ostream& operator<<(ostream& f, const Carte_Ruse& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}

ostream& operator<<(ostream& f, const Carte_Combat& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}

ostream& operator<<(ostream& f, const Carte_Elite& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}

ostream& operator<<(ostream& f, const Carte_chasseur_de_tete& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}
ostream& operator<<(ostream& f, const Carte_Stratege& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}

ostream& operator<<(ostream& f, const Carte_Banshee& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}

ostream& operator<<(ostream& f, const Carte_Traitre& c) {
    cout << "call " << endl;
    f << "carte : " << c.getType();
    return f;
}

Carte_Banshee::Carte_Banshee(string t, string id_) : Carte_Ruse(t, id_) {}

Carte_Traitre::Carte_Traitre(string t, string id_) : Carte_Ruse(t, id_) {}