//
// Created by lucas on 28/05/2023.
//
#include "menu.h"

Menu::Menu() {
    cout << "Bienvenue dans : " << endl;
    cout << "   _____      _           _   _               _______    _   _             \n"
            "  / ____|    | |         | | | |             |__   __|  | | | |            \n"
            " | (___   ___| |__   ___ | |_| |_ ___ _ __      | | ___ | |_| |_ ___ _ __  \n"
            "  \\___ \\ / __| '_ \\ / _ \\| __| __/ _ \\ '_ \\     | |/ _ \\| __| __/ _ \\ '_ \\ \n"
            "  ____) | (__| | | | (_) | |_| ||  __/ | | |    | | (_) | |_| ||  __/ | | |\n"
            " |_____/ \\___|_| |_|\\___/ \\__|\\__\\___|_| |_|    |_|\\___/ \\__|\\__\\___|_| |_|\n"
            "                                                                           \n"
            "                                                                           " << endl;

    cout << "Choisissez le jeu : " << endl;
    cout << "1. Pour Schotten Totten" << endl;
    cout << "2. Pour Schotten Totten 2" << endl;
    cin >> choix_jeu;

    if (choix_jeu == 1) {
        nb_max_joueurs = 2;
        cout << "Schotten Totten selectionne" << endl;
        cout << "Choisissez la variante" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Tactique" << endl;

        cin >> choix_variante;

        if (choix_variante == 1) {
            SetNbParties();
            setJoueurs();
            jeu = new Jeu("Schotten Totten", "normal", nb_parties, nb_joueurs_humains, joueurs);
        }
        else if (choix_variante == 2) {
            SetNbParties();
            setJoueurs();
            jeu = new Jeu("Schotten Totten", "tactique", nb_parties, nb_joueurs_humains, joueurs);
        }
    }

    else {
        cout << "Jeu pas encore implémentée" << endl;

    }


}

void Menu::SetNbParties() {
    cout << "Nombre de parties : " << endl;
    cin >> nb_parties;
    cout << "Nombre de parties qui sera joue : " << nb_parties << endl;
}

void Menu::setJoueurs() {
    cout << "Nombre de joueurs humains : " << endl;
    cin >> nb_joueurs_humains;
    if (nb_joueurs_humains < 0 || nb_joueurs_humains > nb_max_joueurs) {
        throw "erreur : valeur invalide";
    }
    string nom, nom2;
    if (nb_joueurs_humains == 2) {
        cout << "2 joueurs humains" << endl;
        cout << "nom joueur 1 : " << endl;
        cin >> nom;
        //joueurs.push_back(new Joueur(nom, schottenTotten->getNb_Cartes_par_joueur()));
        cout << "nom joueur 2 : " << endl;
        cin >> nom2;
        joueurs.push_back(nom);
        joueurs.push_back(nom2);

    }
    else if (nb_joueurs_humains == 1) {
        cout << "1 joueurs humains" << endl;
        cout << "Entrez le nom du joueur : " << endl;
        cin >> nom;
        joueurs.push_back(nom);
        joueurs.push_back("IA");
    }
}

void Menu::jouer() {
    while (jeu->getNbPartiesJouees() < jeu->getNbParties()) {
        jeu->jouer_tour();
    }
}