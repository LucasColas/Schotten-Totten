//
// Created by lucas on 24/03/2023.
//
#include "Schotten_Totten.h"
#include "Carte.h"
#include "Borne.h"
#include "Affichage_console.h"
#include "iostream"
using namespace std;

initializer_list<Couleur> Couleurs = {Couleur::Rouge, Couleur::Bleu, Couleur::Dore, Couleur::Marron, Couleur::Vert, Couleur::Violet, Couleur::NC};
Schotten_Totten::Schotten_Totten() {
    for (int force = 1; force < 10; force++) {
        for (auto couleur : Couleurs) {
            if (couleur != Couleur::NC) {
                string id = "CarteClan f:"+to_string(force)+" c:"+ toString(couleur);
                cartes.push_back(new Carte_clan( id, couleur, force, "Clan"));
            }
        }
    }

    nb_Cartes_clan = 54;
    nb_bornes = 9;
    nb_cartes_par_joueur = 6;

    for (int i = 0; i < nb_bornes; i++) {
        string id = "B"+ to_string(i+1);
        bornes.push_back(new Borne(id, 0));
        //cout << "borne " << i << " cree : " << *bornes[i] << endl;
    }

}

Tactique::Tactique() {
    /*
    for (int force = 1; force < 10; force++) {
        for (auto couleur : Couleurs) {
            if (couleur != Couleur::NC) {
                string id = "CarteClan f:"+to_string(force)+" c:"+ to_string(static_cast<double>(couleur));
                cartes.push_back(new Carte_clan( id, couleur, force));
            }

        }
    }
     */

    nb_Cartes_clan = 54;
    nb_bornes = 9;
    nb_cartes_par_joueur = 7;
    regles_bornes["Colin-Maillard"] = 1;
    regles_bornes["Combat de Boue"] = 2;
    /*
    for (int i = 0; i < nb_bornes; i++) {
        string id = "Borne_"+ to_string(i);
        bornes.push_back(new Borne(id));
    }
     */
    types.push_back("Elite");
    types.push_back("Combat");
    types.push_back("Ruse");
    cartes_tactique.push_back(new Carte_Traitre("Ruse", "Traitre"));
    for (int i = 0; i < 2; i++) {
        cartes_tactique.push_back(new Carte_Elite("Elite", "Joker_"+ to_string(i), -1, Couleur::NC));
    }
    cartes_tactique.push_back(new Carte_Elite("Elite", "Espion", 7, Couleur::NC));
    cartes_tactique.push_back(new Carte_Elite("Elite", "Porte-Bouclier", -1, Couleur::NC));

    for (auto i : regles_bornes) {
        cartes_tactique.push_back(new Carte_Combat("Combat", i.first, i.second));
    }
    cartes_tactique.push_back(new Carte_chasseur_de_tete("Ruse", "Chasseur de Tête"));
    cartes_tactique.push_back(new Carte_Stratege("Ruse", "Stratège"));
    cartes_tactique.push_back(new Carte_Banshee("Ruse", "Banshee"));


    //cout << "nb bornes" << bornes.size() << endl;
    //cout << "nb cartes clan" << cartes.size() << endl;
}