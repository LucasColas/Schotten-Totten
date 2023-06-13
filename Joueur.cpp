//
// Created by lucas on 24/03/2023.
//

#include "Carte.h"
#include <string>
#include "Joueur.h"
#include "iostream"
#include <random>
using namespace std;

Joueur::Joueur(string n, int nb_cartes, int nb_tactiques_jouees, int joker_j, int nb_p, int nb_b) {
    ia = false;
    nom = n;
    nb_max_cartes = nb_cartes;
    nb_cartes_tactiques_jouees = nb_tactiques_jouees;
    joker_joue = joker_j;
    nb_points = nb_p;
    nb_bornes = nb_b;
}

Carte& Joueur::choix_carte() {
    /*
     * carte que l'utilisateur va jouer. Le num est lié à l'index de la carte stocké dans cartes.
     * S'il rentre 1 alors on joue la carte située à l'index 0, S'il rentre 2 alors on joue la carte située à l'index 1. etc.
    */

    int num_carte;

    cout << "choix carte (nombre entre 1 et " << to_string(cartes.size()) <<  ", 1 etant la carte affichee la plus a gauche.) :\n";
    if (ia) {
        num_carte = IA::choix_entier(1, cartes.size());
    }
    else cin >> num_carte;
    //cout << "carte choisie : " << to_string(num_carte) << endl;
    while (num_carte < 1 || num_carte > nb_max_cartes) {
        cout << "choix carte (nombre entre 1 et " << to_string(cartes.size()) <<  ", 1 etant la carte affichee la plus a gauche.) :\n";
        cin >> num_carte;
    }
    Carte& carte = *cartes[num_carte-1];
    //cout << "carte prise" << endl;
    cartes.erase(cartes.begin()+num_carte-1);
    //cout << "carte supprimee" << endl;
    return carte;

}

int Joueur::choix_borne() {
    //num_borne stocke le numéro de borne où le joueur veut poser sa carte
    int num_borne;
    cout << "choix borne (nombre entre 1 et  " << to_string(nb_bornes) << ", 1 etant la borne le plus a gauche) :\n";
    if (ia) {
        num_borne = IA::choix_entier(1, nb_bornes);
    }
    else cin >> num_borne;
    if (num_borne < 1 || num_borne > nb_bornes) {
        throw "Erreur : nombre invalide";
    }
    return num_borne;
}

void Joueur::ajout_carte(Carte *c) {
    cout << "ajout carte" << endl;

    cartes.push_back(c);
    cout << "carte ajoutee" << endl;

}

void Joueur::setNbPoints(int pts) {
    nb_points = nb_points + pts;
}




//IA
Carte& IA::choix_carte() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,cartes.size());
    int num_carte = distribution(generator);

    //cout << "IA carte choisie : " << to_string(num_carte) << endl;

    Carte& carte = *cartes[num_carte-1];
    //cout << "carte prise" << endl;
    cartes.erase(cartes.begin()+num_carte-1);
    //cout << "carte supprimee" << endl;
    return carte;
}


int IA::choix_borne() {
    //num_borne stocke le numéro de borne où le joueur veut poser sa carte
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,nb_bornes);
    int num_borne = distribution(generator);
    cout << "IA borne choisie : " << num_borne << endl;
    return num_borne;
}

IA::IA(string n, int nb_cartes, int nb_tactiques_jouees, int joker_j, int nb_p, int nb_b) :
Joueur(n, nb_cartes, nb_tactiques_jouees, joker_j = 0, nb_p=0, nb_b=9) {
    ia = true;
}


int IA::choix_entier(const int min, const int max) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution{min, max};
    for (int i = 0; i < 12; ++i) {
        cout << distribution(generator) << endl;
    }
    return distribution(generator);
}


void Joueur::supprimerCarte(int i) {
    Carte& carte = *cartes[i-1];
    cout << "carte prise" << endl;
    cartes.erase(cartes.begin()+i-1);
    cout << "carte supprimee" << endl;
}