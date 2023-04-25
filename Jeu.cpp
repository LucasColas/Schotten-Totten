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
    variantes.push_back("normal");
    variantes.push_back("tactique");


    setNb_parties();
    choix_jeu();
    setNb_joueurs_humains();
    resume();
    cout << "resume fait" << endl;
    creation_joueurs();
    distribution_cartes();
    cout << "cartes distribuees" << endl;


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
            cout << "Pioche et jeu crees" << endl;
        }
        else {
            cout << "Schotten Totten tactique " << endl;
            schottenTotten = new Tactique();
            pioches["pioche tactique"] = new Pioche(schottenTotten->getCartesTactique());
            pioches["pioche clan"] = new Pioche(schottenTotten->getCartesClan());
            defausse = new Defausse();
        }
    }
    affichageConsole = new Affichage_console(variante);
    /*
    for (int i = 0; i < schottenTotten->getNb_Cartes_clan(); i++) {
        cout << schottenTotten->getCarte_clan(i) << endl;
        cout << i << endl;
    }
     */
    cout << "jeu cree" << endl;
}
void Jeu::changer_joueur() {
    if (joueur_actuelle == 1) {
        joueur_actuelle = 2;
    }
    else {
        joueur_actuelle = 1;
    }
    cout << "\n\n\n\n\n\n\n\n\nChangez de joueur et appuyez sur entree ";
    cin.ignore();
    cin.get();
}


void Jeu::jouer_tour() {

    int borne;
    int choix;
    int choix_pioche;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "\t\t\tDebut du tour" << endl;
    cout << "Joueur actuel : " << joueurs[joueur_actuelle-1]->getNom() << endl;
    cout << "----------------------------------------------------" << endl;

    affichageConsole->afficher_cartes_bornes(schottenTotten->bornes, joueur_actuelle);
    affichageConsole->afficher_cartes_joueur(joueurs[joueur_actuelle-1]->getCartes());
    affichageConsole->Afficher_proposition();
    cin >> choix;
    if (choix == 1) {
        borne = joueurs[joueur_actuelle-1]->choix_borne();
        Carte& carte = joueurs[joueur_actuelle-1]->choix_carte();
        if (schottenTotten->bornes[borne-1]->ajout_Carte(&carte, joueur_actuelle)) {
            if (variante == "normal") {
                cout << "carte piochee automatiquement dans la pioche";
                joueurs[joueur_actuelle-1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());

            }
            else {
                affichageConsole->choix_pioche();
                cin >> choix_pioche;
                if (choix_pioche == 1) {
                    joueurs[joueur_actuelle-1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());

                }
                else {
                    joueurs[joueur_actuelle-1]->ajout_carte(&pioches["pioche tactique"]->piocher_carte());
                }

            }
            //Regarder revendication

            //Regarder s'il y a un gagnant pour la partie et regarder si toutes les parties ont été jouées.
            changer_joueur();
        }
        else {
            cout << "pas possible de poser une carte sur cette borne " << endl;
            joueurs[joueur_actuelle-1]->ajout_carte(&carte);
        }
    }

    if (choix == 2 && variante == variantes[1]) {
        //consulter défausse. Fonctionne uniquement en mode tactique.
        affichageConsole->afficher_défausse(*defausse);

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
    //cout << "distribution cartes" << endl;
    for (int i = 0; i < schottenTotten->getNb_Cartes_par_joueur() * 2; i++) {
        //Distribuer cartes
        //cout << "distribue carte" << to_string(i) << endl;
        if (i%2 == 0) {
            cout << "dans i%2" << endl;
            Carte& c = pioches["pioche clan"]->piocher_carte();

            joueurs[0]->ajout_carte(&c);
        }
        else {
            joueurs[1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());
        }
    }
}

