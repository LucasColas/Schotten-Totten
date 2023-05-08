//
// Created by lucas on 24/03/2023.
//

#include <iostream>
#include "Jeu.h"
#include "Schotten_Totten.h"
#include "Pioche.h"
#include "defausse.h"
using namespace std;


Jeu::Jeu(string mode, string v, int nb_max_j) {

    mode_jeu = mode;
    variante = v;
    nb_parties_jouees = 0;
    joueur_actuel = 1;
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
    if (mode_jeu == "Schotten Totten") {
        if (variante == "normal") {
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
    if (joueur_actuel == 1) {
        joueur_actuel = 2;
    }
    else {
        joueur_actuel = 1;
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\nChangez de joueur et appuyez sur entree ";
    cin.ignore();
    cin.get();
}

bool Jeu::action_carte_ruse(Carte& carte_ruse) {
    int choix;
    int choix_pioche;
    int nb_cartes_clan;
    int nb_cartes_tactique;
    int carte_supp;
    int choix_borne;
    int choix2;
    cout << carte_ruse.getId() << endl;

    if (carte_ruse.getId() == "Chasseur de Tête") {


        //proposition();
        cout << "Les choix : " << endl;
        cout << "1. Piochez trois cartes d'une pioche" << endl;
        cout << "2. Piochez trois cartes de deux pioches" << endl;
        cout << "Choisissez ce que vous voulez faire (entrez 1 ou 2):" << endl;
        cin >> choix;
        if (choix == 1) {

            cout << "1. Piochez dans la pioche clan" << endl;
            cout << "2. Piochez dans la pioche tactique" << endl;
            cin >> choix_pioche;

            if (choix_pioche == 1) {
                //Pioche 3 cartes dans la pioche clan
                for (int i = 0; i < carte_ruse.getNb_cartes(); i++) {
                    joueurs[joueur_actuel-1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());
                }
            }

            else if (choix_pioche == 2){
                //Pioche 3 cartes dans la pioche tactique
                for (int i = 0; i < carte_ruse.getNb_cartes(); i++) {
                    joueurs[joueur_actuel-1]->ajout_carte(&pioches["pioche tactique"]->piocher_carte());
                }
            }
            else {
                //Erreur de choix
                cout << "erreur de choix" << endl;
                return false;
            }
        }

        if (choix == 2) {
            //3 cartes dans deux pioches;
            cout << "Combien de cartes de la pioche clan" << endl;
            cin >> nb_cartes_clan;
            if (nb_cartes_clan >= carte_ruse.getNb_cartes()) {
                cout << "erreur trop de cartes ont été piochees." << endl;

            }
            for (int i = 0; i < nb_cartes_clan; i++) {
                joueurs[joueur_actuel-1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());
            }
            cout << "cela fait donc " << to_string(carte_ruse.getNb_cartes() - nb_cartes_clan) << "cartes tactique à piocher" << endl;
            for (int i = 0; i < carte_ruse.getNb_cartes() - nb_cartes_clan; i++) {
                joueurs[joueur_actuel-1]->ajout_carte(&pioches["pioche tactique"]->piocher_carte());
            }
        }

        else {
            //Erreur de choix
            cout << "erreur de choix" << endl;
            return false;
        }
        cout << "voici vos cartes" << endl;
        affichageConsole->afficher_cartes_joueur(joueurs[joueur_actuel-1]->getCartes());
        cout << "vous devez en enlever deux" << endl;
        joueurs[joueur_actuel-1]->choix_carte();
        joueurs[joueur_actuel-1]->choix_carte();

        return true;
    }

    else if (carte_ruse.getId() == "Stratège") {
        cout << "choisissez la borne où vous voulez retirer une de vos cartes (entre 1 et 9)" << endl;
        cin >> choix_borne;
        if (schottenTotten->bornes[choix_borne-1]->GetPossesseur()) {
            cout << "borne revendiquee" << endl;
            return false;
        }
        if (joueur_actuel == 1) {
            cout << "carte que vous pouvez prendre : " << endl;
            if (schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().empty()) {
                cout << "rien n'a prendre ici" << endl;
                return false;
            }
            for (int i = 0; i < schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size(); i++) {
                cout << to_string(i+1) << schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1()[i] << endl;
            }
            cin >> carte_supp;
            if (carte_supp < 1 || carte_supp > schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size()) {
                cout << "erreur valeur" << endl;
                return false;
            }


        }
        else {
            cout << "carte que vous pouvez prendre : " << endl;
            if (schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2().empty()) {
                cout << "rien n'a prendre ici" << endl;
                return false;
            }
            for (int i = 0; i < schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2().size(); i++) {
                cout << to_string(i+1) << schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2()[i] << endl;
            }
            cin >> carte_supp;
            if (carte_supp < 1 || carte_supp > schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2().size()) {
                cout << "erreur valeur" << endl;
                return false;
            }
        }

        Carte& carte = schottenTotten->bornes[choix_borne-1]->supprimer_carte(joueur_actuel, carte_supp-1);
        cout << "Que souhaitez vous faire avec cette carte ?" << endl;
        cout << "1. La mettre sur une autre borne" << endl;
        cout << "2. La défausser" << endl;
        cout << "Entrez 1 ou 2 : " << endl;
        cin >> choix2;

        if (choix2 == 1) {
            //Demander sur quelle borne mettre la carte et ajouter la carte + vérifier la borne
            cout << "sur quelle borne entre (1 et 9) vous voulez mettre cette carte" << endl;
            cin >> choix_borne;
            if (choix_borne < 1 || choix_borne > 9) {
                cout << "erreur nombre" << endl;
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, joueur_actuel);
                return false;
            }
            if (schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, joueur_actuel)) {
                cout << "carte ajoutee" << endl;
                return true;
            }
            else {
                cout << "erreur ajout carte" << endl;
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, joueur_actuel);
                return false;
            }
        }
        else if (choix2 == 2) {

            defausse->ajout_defausse(&carte);
            return true;
        }


    }

    else if (carte_ruse.getId() == "Banshee") {
        cout << "choisissez la borne (entre 1 et 9) ou vous voulez supprimer une carte de votre adversaire" << endl;
        cin >> choix_borne;
        if (choix_borne < 1 || choix_borne > 9) {
            return false;
        }

        if (schottenTotten->bornes[choix_borne-1]->GetPossesseur()) {
            cout << "borne revendiquee" << endl;
            return false;
        }

        cout << "choisissez la carte à supp" << endl;
        if (joueur_actuel == 2) {
            for (int i = 0; i < schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size(); i++) {
                cout << to_string(i+1) << " " << *schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1()[i] << endl;
            }
            cin >> carte_supp;
            if (carte_supp < 1 || carte_supp > schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size()) {
                cout << "carte invalide" << endl;
                return false;
            }
            Carte& carte = schottenTotten->bornes[choix_borne-1]->supprimer_carte(1, carte_supp-1);
            defausse->ajout_defausse(&carte);
            return true;
        }
        if (joueur_actuel == 1) {
            for (int i = 0; i < schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2().size(); i++) {
                cout << to_string(i+1) << " " << *schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2()[i] << endl;
            }
            cin >> carte_supp;
            if (carte_supp < 1 || carte_supp > schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2().size()) {
                cout << "carte invalide" << endl;
                return false;
            }
            Carte& carte = schottenTotten->bornes[choix_borne-1]->supprimer_carte(2, carte_supp-1);
            defausse->ajout_defausse(&carte);
            return true;
        }

    }

    else if (carte_ruse.getId() == "Traître") {
        cout << "choisissez la borne (entre 1 et 9) ou vous voulez supprimer une carte de votre adversaire (et la mettre de votre cote)" << endl;
        cin >> choix_borne;
        if (choix_borne < 1 || choix_borne > 9) {
            return false;
        }

        if (schottenTotten->bornes[choix_borne-1]->GetPossesseur()) {
            cout << "borne revendiquee" << endl;
            return false;
        }

        cout << "choisissez la carte à supp" << endl;
        if (joueur_actuel == 2) {
            for (int i = 0; i < schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size(); i++) {
                cout << to_string(i+1) << " " << schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1()[i] << endl;
            }
            cin >> carte_supp;
            if (carte_supp < 1 || carte_supp > schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size()) {
                cout << "carte invalide" << endl;
                return false;
            }
            Carte& carte = schottenTotten->bornes[choix_borne-1]->supprimer_carte(1, carte_supp-1);
            cout << "sur quelle borne vous souhaitez ajouter la carte (entre 1 et 9)" << endl;

            cin >> choix_borne;
            if (choix_borne < 1 || choix_borne > 9) {
                cout << "erreur borne invalide";
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, 1);
                return false;
            }

            if (schottenTotten->bornes[choix_borne-1]->GetPossesseur()) {
                cout << "erreur borne revendiquee" << endl;
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, 1);
                return false;
            }


            if (joueur_actuel == 2 and schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2().size() == schottenTotten->bornes[choix_borne-1]->getNbMaxCartes()) {
                cout << "borne pleine" << endl;
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, 1);
                return false;
            }
            return true;
        }
        if (joueur_actuel == 1) {
            for (int i = 0; i < schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size(); i++) {
                cout << to_string(i+1) << " " << schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1()[i] << endl;
            }
            cin >> carte_supp;
            if (carte_supp < 1 || carte_supp > schottenTotten->bornes[choix_borne-1]->getCartes_joueur_1().size()) {
                cout << "carte invalide" << endl;
                return false;
            }
            Carte& carte = schottenTotten->bornes[choix_borne-1]->supprimer_carte(2, carte_supp-1);
            cout << "sur quelle borne vous souhaitez ajouter la carte (entre 1 et 9)" << endl;

            cin >> choix_borne;
            if (choix_borne < 1 || choix_borne > 9) {
                cout << "erreur borne invalide";
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, 2);
                return false;
            }

            if (schottenTotten->bornes[choix_borne-1]->GetPossesseur()) {
                cout << "erreur borne revendiquee" << endl;
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, 2);
                return false;
            }



            if (joueur_actuel == 2 and schottenTotten->bornes[choix_borne-1]->getCartes_joueur_2().size() == schottenTotten->bornes[choix_borne-1]->getNbMaxCartes()) {
                cout << "borne pleine" << endl;
                schottenTotten->bornes[choix_borne-1]->ajout_Carte(&carte, 2);
                return false;
            }

            return true;
        }
    }

    //defausse->ajout_defausse(&carte_ruse);

    return true;
}

void Jeu::choixPioche() {
    int choix_pioche;
    if (variante == "normal") {
        cout << "carte piochee automatiquement dans la pioche";
        joueurs[joueur_actuel-1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());

    }
    else {
        affichageConsole->choix_pioche();
        cin >> choix_pioche;
        if (choix_pioche == 1) {
            joueurs[joueur_actuel-1]->ajout_carte(&pioches["pioche clan"]->piocher_carte());

        }
        else if (choix_pioche == 2) {
            joueurs[joueur_actuel-1]->ajout_carte(&pioches["pioche tactique"]->piocher_carte());
        }
        else {
            cout << "mauvais nombre entree" << endl;
            return;
        }

    }
}

int Jeu::autreJoueur() {
    if (joueur_actuel == 1) {
        return 1;
    }
    return 0;
}

void Jeu::jouer_tour() {

    int borne;
    int choix;
    int choix_pioche;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "\t\t\tDebut du tour" << endl;
    cout << "Joueur actuel : " << joueurs[joueur_actuel-1]->getNom() << endl;
    cout << "----------------------------------------------------" << endl;

    affichageConsole->afficher_cartes_bornes(schottenTotten->bornes, joueur_actuel);
    affichageConsole->afficher_cartes_joueur(joueurs[joueur_actuel-1]->getCartes());
    affichageConsole->Afficher_proposition();
    cin >> choix;
    if (choix == 1) {

        Carte& carte = joueurs[joueur_actuel-1]->choix_carte();
        //vérifier que la carte peut-être posée sur une borne ou pas.
        //cout << "on a la carte" << endl;
        cout << "carte : " << carte.getType() << endl;
        if (carte.getType() != "Clan" && joueurs[joueur_actuel-1]->getNbTactiqueJouees() > joueurs[autreJoueur()]->getNbTactiqueJouees())
        {
            cout << "vous avez jouez plus de cartes tactique que votre adversaire" << endl;
            joueurs[joueur_actuel-1]->ajout_carte(&carte);
            return;
        }
        if (carte.getType() == "Combat") {
            //Cas ou la carte est une carte tactique de combat
            cout << "Choisissez la borne ou voulez poser la carte Combat (nombre entre 1 et 9, 1 etant la borne la plus a gauche)" << endl;
            cin >> borne;
            if (borne < 1 || borne > 9) {
                cout << "mauvaise borne" << endl;
                joueurs[joueur_actuel-1]->ajout_carte(&carte);
                return;
            }

            if (schottenTotten->bornes[borne-1]->GetPossesseur()) {
                cout << "borne déjà revendiquee" << endl;
                return;
            }
            schottenTotten->bornes[borne-1]->ajoutRegle(carte.getRegle());
            joueurs[joueur_actuel-1]->carteTactiqueJouee();
            return;
        }

        if (carte.getType() == "Ruse") {
            if (action_carte_ruse(carte)) {
                defausse->ajout_defausse(&carte);
                choixPioche();
                changer_joueur();
                joueurs[joueur_actuel-1]->carteTactiqueJouee();
                return;
            }
            joueurs[joueur_actuel-1]->ajout_carte(&carte);
            return;
        }


        borne = joueurs[joueur_actuel-1]->choix_borne();

        if (schottenTotten->bornes[borne-1]->ajout_Carte(&carte, joueur_actuel)) {
            choixPioche();
            joueurs[joueur_actuel-1]->carteTactiqueJouee();
            //Regarder revendication

            //Regarder s'il y a un gagnant pour la partie et regarder si toutes les parties ont été jouées.
            if (carte.getType() == "Elite") {
                joueurs[joueur_actuel-1]->carteTactiqueJouee();
            }
            changer_joueur();
        }
        else {
            cout << "pas possible de poser une carte sur cette borne " << endl;
            joueurs[joueur_actuel-1]->ajout_carte(&carte);
        }
    }

    if (choix == 2 && variante == variantes[1]) {
        //consulter défausse. Fonctionne uniquement en mode tactique.
        affichageConsole->afficher_défausse(*defausse);

    }

    //Revendication de bornes manuelles

    if (verif()) {
        nb_parties_jouees++;
        //Afficher le joueur qui a gagné la partie
        if (nb_parties == nb_parties_jouees) {
            //Afficher le joueur qui a gagne le plus de points.
        }
    }

}

bool Jeu::verif() {
    //appel algo revendication

    return false;
}

void Jeu::designe_premier_joueur() {
    cout << "Lequel des deux joueurs a voyagé le plus récemment le plus près de l'Ecosse (Joueur 1 ou Joueur 2) ?";
    cin >> joueur_actuel;
    if (joueur_actuel != 1 && joueur_actuel != 2) {
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

void Jeu::revendication_borne(int i) {

    if (!schottenTotten->bornes[i]->GetPossesseur() && schottenTotten->bornes[i]->getCartes_joueur_1().size() ==
        schottenTotten->bornes[i]->getCartes_joueur_2().size() && schottenTotten->bornes[i]->getCartes_joueur_1().size() == schottenTotten->bornes[i]->getNbMaxCartes()) {
        //Les deux ont le max de cartes
        revendication = new Revendication(schottenTotten->bornes[i]);


    }



}