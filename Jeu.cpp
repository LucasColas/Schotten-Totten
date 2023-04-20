//
// Created by lucas on 24/03/2023.
//

#include <iostream>
#include "Jeu.h"
#include "Schotten_Totten.h"
#include "Pioche.h"
using namespace std;


Jeu::Jeu(string mode, string v, int nb_max_j) {

    mode_jeu = mode;
    variante = v;
    nb_parties_jouees = 0;
    joueur_actuelle = 1;
    //schottenTotten = new Schotten_Totten();
    nb_max_joueurs = nb_max_j;


    setNb_parties();
    choix_jeu();
    setNb_joueurs_humains();
    resume();
    cout << "resumé fait" << endl;
    creation_joueurs();
    distribution_cartes();
    cout << "cartes distribuées" << endl;


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
            cout << "Schotten Totten cree" << endl;
            Pioche* pioche = new Pioche(schottenTotten->getCartesClan());
            pioches["pioche clan"] = pioche;
            cout << "Pioche et jeu crées" << endl;
        }
        else {
            cout << "Schotten Totten tactique " << endl;
            schottenTotten = new Tactique();
            pioches["pioche tactique"] = new Pioche(schottenTotten->getCartesTactique());
            pioches["pioche clan"] = new Pioche(schottenTotten->getCartesClan());
        }
    }
    affichageConsole = new Affichage_console(variante);
    /*
    for (int i = 0; i < schottenTotten->getNb_Cartes_clan(); i++) {
        cout << schottenTotten->getCarte_clan(i) << endl;
        cout << i << endl;
    }
     */
    cout << "jeu crée" << endl;
}


void Jeu::jouer_tour() {
    affichageConsole->afficher_cartes_bornes(schottenTotten->bornes, joueur_actuelle);
    int borne;

    if (joueur_actuelle == 1) {
        cout << "Joueur 1 à ton tour" << endl;
    }

    else {
        cout << "Joueur 2 à ton tour" << endl;
    }

    borne = joueurs[joueur_actuelle-1]->choix_borne();
    Carte& carte = joueurs[joueur_actuelle-1]->choix_carte();
    schottenTotten->bornes[borne-1]->ajout_Carte(&carte, joueur_actuelle);
    if (variante.compare("normal")) {
        joueurs[joueur_actuelle-1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());
    }


}

void Jeu::designe_premier_joueur() {
    cout << "Lequel des deux joueurs a voyagé le plus récemment le plus près de l'Ecosse (Joueur 1 ou Joueur 2) ?";
    cin >> joueur_actuelle;
    if (joueur_actuelle != 1 && joueur_actuelle != 2) {
        throw "erreur : valeur invalide";
    }
}

void Jeu::setNb_joueurs_humains() {
    cout << "Nombre de joueurs humains : " << endl;
    cin >> nb_joueurs_humains;
    if (nb_joueurs_humains < 0 || nb_joueurs_humains > nb_max_joueurs) {
        throw "erreur : valeur invalide";
    }



}

void Jeu::creation_joueurs() {
    string nom;
    if (nb_joueurs_humains == 2) {
       cout << "2 joueurs humains" << endl;
       cout << "nom joueur 1 : " << endl;
       cin >> nom;
       joueurs.push_back(new Joueur(nom, schottenTotten->getNb_Cartes_par_joueur()));
       cout << "nom joueur 2 : " << endl;
       cin >> nom;
       joueurs.push_back(new Joueur(nom, schottenTotten->getNb_Cartes_par_joueur()));
    }
}

void Jeu::resume() {
    cout << "Nombre de parties : " << nb_parties << " Nombre de joueurs humains : " << nb_joueurs_humains << " mode : " << mode_jeu <<  " variante : " << variante << endl;
}

void Jeu::distribution_cartes() {
    cout << "distribution cartes" << endl;
    for (int i = 0; i < schottenTotten->getNb_Cartes_par_joueur() * 2; i++) {
        //Distribuer cartes
        cout << "distribue carte" << to_string(i) << endl;
        if (i%2 == 0) {
            cout << "dans i%2" << endl;
            Carte c = pioches["pioche clan"]->piocher_carte();

            joueurs[0]->ajout_carte(&c);
        }
        else {
            joueurs[1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());
        }
    }
}

