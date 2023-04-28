//
// Created by lucas on 25/03/2023.
//
#include "Affichage_console.h"
#include "Carte.h"
#include <iostream>
#include <conio.h>
using namespace std;

Affichage_console::Affichage_console(string v) {
    variante = v;

}

void Affichage_console::afficher_cartes_bornes(vector<Borne *> &Bornes, int joueur_actuelle) {
    /*
     *
     * On affiche en haut les cartes du joueur qui ne joue pas
     */
    //int espace = 0;
    string espace = "   ";
    string espace_large = "     ";
    int max_cartes = 0;
    //cout << "plateau" << endl;


    for (int i = 0; i < Bornes.size(); i++) {
        if (joueur_actuelle == 1) {
            if (Bornes[i]->getCartes_joueur_2().size() > max_cartes) {
                max_cartes = Bornes[i]->getCartes_joueur_2().size();
            }
        }

        else {
            if (Bornes[i]->getCartes_joueur_1().size() > max_cartes) {
                max_cartes = Bornes[i]->getCartes_joueur_1().size();
            }
        }

    }
    //cout << "cartes joueur haut" << endl;
    for (int j = 0; j < max_cartes; j++) {
        for (int i = 0; i < Bornes.size(); i++) {

            if (joueur_actuelle == 2){
                if (Bornes[i]->getCartes_joueur_1().size() > j) {
                    cout << *(Bornes[i]->getCartes_joueur_1()[j]) << " ";
                }
                else {
                    cout << espace_large;
                }
            }

            else {
                if (Bornes[i]->getCartes_joueur_2().size() > j) {
                    cout << *(Bornes[i]->getCartes_joueur_2()[j]) << "  ";
                }
                else {
                    cout << espace_large;
                }
            }

        }
        cout << endl;
        //espace = 0;
    }
    //cout << "\n\n";
    //cout << "borne" << endl;
    /*
     * Les bornes
     */
    for (int i = 0; i < Bornes.size(); i++) {
        //cout << i << " : ";
        cout << *Bornes[i] << espace;

    }
    cout << endl;

    /*
     * Les cartes du joueur actuel
     */
    //cout << "carte en dessous" << endl;
    for (int i = 0; i < Bornes.size(); i++) {
        if (joueur_actuelle == 1) {
            if (Bornes[i]->getCartes_joueur_1().size() > max_cartes) {
                max_cartes = Bornes[i]->getCartes_joueur_1().size();
            }
        }

        else {
            if (Bornes[i]->getCartes_joueur_2().size() > max_cartes) {
                max_cartes = Bornes[i]->getCartes_joueur_2().size();
            }
        }

    }

    for (int j = 0; j < max_cartes; j++) {
        for (int i = 0; i < Bornes.size(); i++) {
            if (joueur_actuelle == 1) {
                if (Bornes[i]->getCartes_joueur_1().size() > j) {
                    cout << *(Bornes[i]->getCartes_joueur_1()[j]) << " ";
                }
                else {
                    cout << espace_large;
                }
            }

            else {
                if (Bornes[i]->getCartes_joueur_2().size() > j) {
                    cout << *(Bornes[i]->getCartes_joueur_2()[j]) << " ";
                }
                else {
                    cout << espace_large;
                }
            }

        }
        cout << endl;
    }


}

void Affichage_console::afficher_cartes_joueur(vector<Carte *> &cartes) {
    cout << "Cartes du joueur : ";
    for (int i = 0; i < cartes.size(); i++) {
        //cout << "carte";
        //cout << "carte : " << cartes[i]->getType();
        cout << *cartes[i] << "  ";
    }
    cout << endl;
}

void Affichage_console::afficher_bornes(vector<Borne *> &Bornes) {
    for (int i = 0; i < Bornes.size(); i++) {
        cout << Bornes[i];
    }
}

void Affichage_console::Afficher_proposition() {
    cout << "Entrez un des choix " << endl;
    cout << "1 : Placer carte" << endl;
    if (variante == "tactique") {
        cout << "2: consulter defausse" << endl;
    }
}

void Affichage_console::choix_pioche() {
    cout << "Choissisez dans quelle pioche vous voulez piocher" << endl;
    cout << "1 : pioche cartes clan" << endl;
    cout << "2 : pioche cartes tactique" << endl;
}

void Affichage_console::Afficher_jeu(vector<Borne*>& Bornes, int joueur_actuelle) {

    afficher_cartes_bornes(Bornes, joueur_actuelle);
    Afficher_proposition();
}

void Affichage_console::afficher_défausse(const Defausse &d) {
    if (d.estVide()) {
        cout << "defausse vide" << endl;
        cout << "appuyer sur entree pour sortir de la defausse" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    size_t nb = d.getNbCartes();
    //size_t i = 0;
    size_t nb_cartes_affichees = 7;
    //int continuer = 1;


    for (size_t j = 0; j < nb; j++) {
        cout << d.getCarte(j) << "  ";
        if (j%nb_cartes_affichees == 0) {
            cout << endl;
        }
    }
}