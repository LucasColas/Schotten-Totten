//
// Created by lucas on 24/03/2023.
//

#include "Carte.h"
#include <string>
#include "Joueur.h"
#include "iostream"
using namespace std;

Joueur::Joueur(string n, int nb_cartes, int nb_tactiques_jouees, int joker_j, int nb_p, int nb_b) {
    nom = n;
    nb_max_cartes = nb_cartes;
    nb_cartes_tactiques_jouees = nb_tactiques_jouees;
    joker_joue = joker_j;
    nb_points = nb_p;
    nb_bornes = nb_b;
}

Carte& Joueur::choix_carte() {
    /*
     * carte que l'utilisateur va jouer. Le num est lié à l'index de la carte stockées dans cartes.
     * S'il rentre 1 alors on joue la carte située à l'index 0, S'il rentre 2 alors on joue la carte située à l'index 1.
    */

    int num_carte;

    cout << "choix carte (nombre entre 1 et " << to_string(nb_max_cartes) <<  ", 1 etant la carte affichée la plus a gauche.)";
    cin >> num_carte;
    //cout << "choix borne (nb entre 1 et 9, 1 la borne la plus a gauche)";
    if (num_carte < 1 || num_carte > nb_max_cartes) {
        throw "erreur";
    }
    Carte& carte = *cartes[num_carte-1];
    cartes.erase(cartes.begin()+num_carte-1);
    return carte;

}

int Joueur::choix_borne() {
    //num_borne stocke le numéro de borne où le joueur veut poser sa carte
    int num_borne;
    cout << "choix borne (nombre entre 1 et  " << to_string(nb_bornes) << ", 1 etant la borne le plus a gauche)";
    cin >> num_borne;
    if (num_borne < 1 || num_borne > nb_bornes) {
        throw "Erreur : nombre invalide";
    }
    return num_borne;
}

void Joueur::ajout_carte(Carte *c) {
    cout << "ajout carte" << endl;
    if (cartes.size() < nb_max_cartes) {
        cartes.push_back(c);
        cout << "carte ajoutee" << endl;
    }
}