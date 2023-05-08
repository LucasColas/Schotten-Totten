//
// Created by lucas on 06/05/2023.
//
#include "Revendication.h"
map<string, int> Revendication::rank = {{"Suite couleur", 1}, {"Brelan", 2}, {"Couleur", 3}, {"Suite", 4}, {"Somme", 5}};
Revendication::Revendication(Borne* b)
{
    max_cartes_pose = b->getNbMaxCartes();
    historique = b->getHistorique();
    regles = b->getRegles();
    cartes_joueur1 = b->getCartes_joueur_1();
    cartes_joueur2 = b->getCartes_joueur_2();

}

void Revendication::MeilleureCombinaison() {
    //Donner la meilleure combinaison;
    //Savoir déjà s'il y a des cartes tactiques
    //S'il y a des cartes tactiques alors déterminer la meilleure combinaison selon
    //Les valeurs possibles de ces cartes.
    int carte_tactique_joueur1 = 0;
    int carte_tactique_joueur2 = 0;
    for (auto c : cartes_joueur1) {
        if (c->getType() != "Clan")
            carte_tactique_joueur1++;
    }

    for (auto c: cartes_joueur2) {
        if (c->getType() != "Clan")
            carte_tactique_joueur2++;
    }

    for (auto c1: cartes_joueur1) {
        //
    }

}

int Revendication::Revendiquer() {
    if (max_cartes_pose) {
        return Revendiquant_avec_max_cartes();
    }

    return 0;
}

int Revendication::Revendiquant_avec_max_cartes() {
    int puissance_joueur1 = combinaison_joueur1->getPuissance();
    int puissance_joueur2 = combinaison_joueur2->getPuissance();
    int somme_joueur1;
    int somme_joueur2;
    for (auto r : regles) {
        if (r == 1) {
            somme_joueur1 = combinaison_joueur1->getSommeSuite();
            somme_joueur2 = combinaison_joueur2->getSommeSuite();
            if (somme_joueur1 > somme_joueur2) {
                return 1;
            }
            else if (somme_joueur2 > somme_joueur1) {
                return 2;
            }
            else if (somme_joueur1 == somme_joueur2) {
                //Si toujours égal regarder qui a posé la troisième carte en premier
                return historique;
            }

        }
    }
    if (puissance_joueur1 == puissance_joueur2) {
        //calculer la somme des cartes.
        somme_joueur1 = combinaison_joueur1->getSommeSuite();
        somme_joueur2 = combinaison_joueur2->getSommeSuite();
        if (somme_joueur1 > somme_joueur2) {
            return 1;
        }
        else if (somme_joueur2 > somme_joueur1) {
            return 2;
        }
        else if (somme_joueur1 == somme_joueur2) {
            //Si toujours égal regarder qui a posé la troisième carte en premier
            return historique;
        }

    }
    else if (puissance_joueur1 > puissance_joueur2) {
        return 1;
    }

    else if (puissance_joueur1 < puissance_joueur2) {
        return 2;
    }

    return 0;
}