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
    for (int j = max_cartes - 1; j >= 0; j--) {
        for (int i = 0; i < Bornes.size(); i++) {

            if (joueur_actuelle == 2){
                if (Bornes[i]->getCartes_joueur_1().size() >= max_cartes) {
                    cout << *(Bornes[i]->getCartes_joueur_1()[j]) << " ";
                }
                else {
                    cout << "___";
                }
            }

            else {
                if (Bornes[i]->getCartes_joueur_2().size() >= max_cartes) {
                    cout << *(Bornes[i]->getCartes_joueur_2()[j]) << " ";
                }
                else {
                    cout << "___";
                }
            }

        }
        cout << endl;
        //espace = 0;
    }
    //cout << "\n\n";
    //cout << "borne" << endl;

    for (int i = 0; i < Bornes.size(); i++) {
        //cout << i << " : ";
        cout << *Bornes[i] << " ";

    }
    cout << endl;
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
                    cout << "   ";
                }
            }

            else {
                if (Bornes[i]->getCartes_joueur_2().size() > j) {
                    cout << *(Bornes[i]->getCartes_joueur_2()[j]) << " ";
                }
                else {
                    cout << "   ";
                }
            }


        }
        cout << endl;
    }


}

void Affichage_console::afficher_cartes_joueur(vector<Carte *> &cartes) {
    for (int i = 0; i < cartes.size(); i++) {
        cout << "carte";
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

void Affichage_console::Afficher_jeu(vector<Borne*>& Bornes, int joueur_actuelle) {

    afficher_cartes_bornes(Bornes, joueur_actuelle);
    Afficher_proposition();
}

void Affichage_console::afficher_défausse(const Defausse &d) {
    size_t nb = d.getNbCartes();
    size_t i = 0;
    size_t nb_cartes_affichees = 7;
    int continuer = 1;

    while (i < nb && !continuer) {
        for (size_t j = i; j < i+nb_cartes_affichees; j++) {
            //
            //Afficher carte. Besoin de surcharge d'opérateurs.
            //
        }
        cout << "continuer (1) ou sortir (0)";
        cin >> continuer;
    }
}