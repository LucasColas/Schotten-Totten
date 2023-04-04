//
// Created by lucas on 24/03/2023.
//

#include "Carte.h"
#include <string>
#include "Joueur.h"
#include "iostream"
using namespace std;

Joueur::Joueur(string n, int nb_cartes, int nb_tactiques_jouees, int joker_j, int nb_p) {
    nom = n;
    nb_max_cartes = nb_cartes;
    nb_cartes_tactiques_jouees = nb_tactiques_jouees;
    joker_joue = joker_j;
    nb_points = nb_p;
}

Carte& Joueur::choix_carte() {
    /*
     * carte que l'utilisateur va jouer. Le num est lié à l'index de la carte stockées dans cartes.
     * S'il rentre 1 alors on joue la carte située à l'index 0, S'il rentre 2 alors on joue la carte située à l'index 1.
    */

    int num_carte;

    cout << "choix carte (nombre entre 1 et 7, 1 étant la carte affichée la plus à gauche.)";
    cin >> num_carte;
    cout << "choix borne (nb entre 1 et 9, 1 la borne la plus à gauche)";
    return *cartes[num_carte-1];

}

int Joueur::choix_borne() {
    int num_borne;
    cout << "choix borne (nombre entre 1 et 9, 1 étant la borne le plus à gauche)";
    cin >> num_borne;
    return num_borne;
}