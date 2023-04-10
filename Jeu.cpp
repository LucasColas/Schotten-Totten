//
// Created by lucas on 24/03/2023.
//

#include <iostream>

#include "Jeu.h"
#include "Schotten_Totten.h"
#include "Pioche.h"
using namespace std;


Jeu::Jeu(string mode, string v) {

    mode_jeu = mode;
    variante = v;
    nb_parties_jouees = 0;
    joueur_actuelle = 1;
    schottenTotten = new Schotten_Totten();


    setNb_parties();
    choix_jeu();
    setNb_joueurs_humains();
    resume();
    distribution_cartes();
    creation_joueurs();

}

void Jeu::setNb_parties() {
    cout << "Nombre de parties : " << endl;
    cin >> nb_parties;
    cout << "Nombre de parties qui sera joue : " << nb_parties << endl;

}

void Jeu::choix_jeu() {
    if (mode_jeu.compare("Schotten Totten") == 0) {
        if (variante.compare("normal") == 0) {
            cout << "Schotten Totten normal " << endl;
            schottenTotten = new Schotten_Totten();
            pioche = new Pioche(5);

        }
        else {
            cout << "Schotten Totten tactique " << endl;
            schottenTotten = new Tactique();
        }
    }
    affichageConsole = new Affichage_console(variante);
    for (int i = 0; i < schottenTotten->getNb_Cartes_clan(); i++) {
        cout << schottenTotten->getCarte_clan(i) << endl;
        cout << i << endl;
    }
}

void Jeu::joueur_tour() {
    if (joueur_actuelle == 1) {
        cout << "Joueur 1 à ton tour" << endl;
    }

    else {
        cout << "Joueur 2 à ton tour" << endl;
    }
}

void Jeu::setNb_joueurs_humains() {
    cout << "Nombre de joueurs humains : " << endl;
    cin >> nb_joueurs_humains;
}

void Jeu::creation_joueurs() {
    string nom;
    if (nb_joueurs_humains == 2) {
       cout << "2 joueurs humains" << endl;
       cout << "nom joueur 1 : " << endl;
       cin >> nom;
       joueurs.push_back(new Joueur(nom, schottenTotten->getNb_Cartes_par_joueur()));
       cout << "nom joueur 1 : " << endl;
       cin >> nom;
       joueurs.push_back(new Joueur(nom, schottenTotten->getNb_Cartes_par_joueur()));
    }
}

void Jeu::resume() {
    cout << "Nombre de parties : " << nb_parties << " Nombre de joueurs humains : " << nb_joueurs_humains << " mode : " << mode_jeu <<  " variante : " << variante << endl;
}

void Jeu::distribution_cartes() {
    for (int i = 0; i < schottenTotten->getNb_Cartes_par_joueur() * 2; i++) {
        //Distribuer cartes
        if (i%2 == 0) {
            joueurs[0]->ajout_carte(&pioches["pioches tactique"]->piocher_carte());
        }
    }
}

