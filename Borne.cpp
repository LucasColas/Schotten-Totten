//
// Created by lucas on 06/05/2023.
//
#include "Borne.h"
Borne::Borne(string id_, int r, int nb_cartes, int p) {
    id = id_;
    regles.push_back(r);
    nb_max_cartes = nb_cartes;
    possesseur = p;

}

bool Borne::ajoutRegle(int r) {
    regles.push_back(r);

    return true;
}

ostream& operator<<(ostream& f, const Borne& b) {
    //cout << "call " << endl;
    f << b.getId();
    return f;
}



bool Borne::ajout_Carte(Carte *c, int joueur_actuelle) {
    if (possesseur) {
        cout << "borne déjà revendiquee" << endl;
        return false;
    }
    if (joueur_actuelle == 1) {
        if (cartes_joueur_1.size() == nb_max_cartes) {
            cout << "pas possible de mettre une carte ici";
            return false;
        }
        cartes_joueur_1.push_back(c);
        if (cartes_joueur_1.size() == nb_max_cartes && cartes_joueur_2.size() < nb_max_cartes) {
            historique = 1;
        }

    }
    else {
        if (cartes_joueur_2.size() == nb_max_cartes) {
            cout << "pas possible de mettre une carte ici";
            return false;
        }
        cartes_joueur_2.push_back(c);
        if (cartes_joueur_2.size() == nb_max_cartes && cartes_joueur_1.size() < nb_max_cartes) {
            historique = 2;
        }
    }
    return true;
}

Carte& Borne::supprimer_carte(int joueur, int num) {

    if (joueur == 1) {

        Carte& carte = *cartes_joueur_1[num];
        cartes_joueur_1.erase(cartes_joueur_1.begin() + num);
        return carte;
    }

    Carte& carte = *cartes_joueur_2[num];
    cartes_joueur_2.erase(cartes_joueur_2.begin() + num);
    return carte;


}

bool Borne::possible_revendication() {

    if (nb_max_cartes == 4) {
        return (cartes_joueur_1.size() == nb_max_cartes && cartes_joueur_2.size() == nb_max_cartes);
    }
    return ((cartes_joueur_1.size() == nb_max_cartes && cartes_joueur_2.size() >= 2) || (cartes_joueur_2.size() == nb_max_cartes && cartes_joueur_1.size() >= 2));

}
void Borne::demander_valeurs(int joueur_actuel) {

    if (joueur_actuel == 1) {
        for (auto c : cartes_joueur_1) {
            if (c->get_force() == -1) {
                c->setForce();
            }
            if (c->get_couleur() == Couleur::NC) {
                c->setCouleur();
            }
        }
    }
}

void Borne::creerCombinaison_joueur1() {
    combinaison_joueur_1 = new Combinaison(cartes_joueur_1[0], cartes_joueur_1[1], cartes_joueur_1[2], 3);
}

void Borne::creerCombinaison_joueur2() {
    combinaison_joueur_2 = new Combinaison(cartes_joueur_2[0], cartes_joueur_2[1], cartes_joueur_2[2], 3);
}

void Borne::setPossesseur(int joueur) {
    possesseur = joueur;
}