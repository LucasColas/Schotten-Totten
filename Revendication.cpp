//
// Created by lucas on 06/05/2023.
//
#include "Revendication.h"
#include "Carte.h"
map<string, int> Revendication::rank = {{"Suite couleur", 1}, {"Brelan", 2}, {"Couleur", 3}, {"Suite", 4}, {"Somme", 5}};
Revendication::Revendication(Borne* b)
{
    nb_cartes_max = b->getNbMaxCartes();
    historique = b->getHistorique();
    regles = b->getRegles();
    cartes_joueur1 = b->getCartes_joueur_1();
    cartes_joueur2 = b->getCartes_joueur_2();
    /*
    if (nb_cartes_max == 3) {
        combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1], cartes_joueur1[2], max_cartes_pose);
        combinaison_joueur2 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1], cartes_joueur2[2], max_cartes_pose);

    }

    else if (nb_cartes_max == 4) {
        combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1], cartes_joueur1[2], cartes_joueur1[3],max_cartes_pose);
        combinaison_joueur2 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1], cartes_joueur2[2], cartes_joueur2[3],max_cartes_pose);

    }
     */
    joueur1 = 1;
    joueur2 = 2;

}

void Revendication::MeilleureCombinaison() {
    //Donner la meilleure combinaison;
    //Savoir déjà s'il y a des cartes tactiques
    //S'il y a des cartes tactiques alors déterminer la meilleure combinaison selon
    //Les valeurs possibles de ces cartes.
    int carte_tactique_joueur1 = 0;
    int carte_tactique_joueur2 = 0;
    for (auto c : cartes_joueur1) {
        if (c->getType() != "Clan")
            carte_tactique_joueur1++;
    }

    for (auto c: cartes_joueur2) {
        if (c->getType() != "Clan")
            carte_tactique_joueur2++;
    }

    for (auto c1: cartes_joueur1) {
        //
    }

}

int Revendication::Revendiquer() {
    if (max_cartes_pose) {
        return Revendiquant_avec_max_cartes();
    }

    return 0;
}

int Revendication::Revendiquant_avec_max_cartes() {
    if (cartes_joueur1.size() == 3) {
        combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1],
                                              cartes_joueur1[2], 3);
        combinaison_joueur2 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1],
                                              cartes_joueur2[2], 3);

    }

    else if (cartes_joueur1.size() == 4) {
        combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1],
                                              cartes_joueur1[2], cartes_joueur1[3], 3);
        combinaison_joueur2 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1],
                                              cartes_joueur2[2], cartes_joueur2[3],3);

    }

    int puissance_joueur1 = combinaison_joueur1->getPuissance();
    int puissance_joueur2 = combinaison_joueur2->getPuissance();
    int somme_joueur1;
    int somme_joueur2;
    for (auto r : regles) {
        if (r == 1) {
            somme_joueur1 = combinaison_joueur1->getSommeSuite();
            somme_joueur2 = combinaison_joueur2->getSommeSuite();
            if (somme_joueur1 > somme_joueur2) {
                return 1;
            }
            else if (somme_joueur2 > somme_joueur1) {
                return 2;
            }
            else if (somme_joueur1 == somme_joueur2) {
                //Si toujours égal regarder qui a posé la troisième carte en premier
                return historique;
            }

        }
    }
    if (puissance_joueur1 == puissance_joueur2) {
        //calculer la somme des cartes.
        somme_joueur1 = combinaison_joueur1->getSommeSuite();
        somme_joueur2 = combinaison_joueur2->getSommeSuite();
        if (somme_joueur1 > somme_joueur2) {
            return joueur1;
        }
        else if (somme_joueur2 > somme_joueur1) {
            return joueur2;
        }
        else if (somme_joueur1 == somme_joueur2) {
            //Si toujours égal regarder qui a posé la troisième carte en premier
            return historique;
        }

    }
    else if (puissance_joueur1 > puissance_joueur2) {
        return joueur1;
    }

    else if (puissance_joueur1 < puissance_joueur2) {
        return joueur2;
    }

    return 0;
}

int Revendication::Revendiquer_sans_max_cartes(vector<Carte*>& cartes, vector<Carte*>& cartes_tactique) {
    int joueur_sans_max_cartes;
    vector<Carte*> cartes_outs;
    int puissance_joueur_max_cartes;
    bool carte_deja_ajoute = false;
    if (cartes_joueur1.size() > cartes_joueur2.size()) {
        joueur_sans_max_cartes = joueur2;
        if (nb_cartes_max == 3) {
            combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1], cartes_joueur1[2], nb_cartes_max);

        }
        else if (nb_cartes_max == 4) {
            combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1], cartes_joueur1[2], cartes_joueur1[3], nb_cartes_max);

        }

        puissance_joueur_max_cartes = combinaison_joueur1->getPuissance();
    }

    else {
        joueur_sans_max_cartes = joueur1;
        if (nb_cartes_max == 3) {
            combinaison_joueur2 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1], cartes_joueur2[2], nb_cartes_max);

        }
        else if (nb_cartes_max == 4) {
            combinaison_joueur1 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1], cartes_joueur2[2], cartes_joueur2[3], nb_cartes_max);

        }
        puissance_joueur_max_cartes = combinaison_joueur2->getPuissance();
    }
    if (nb_cartes_max-joueur_sans_max_cartes == 1) {
        for (auto c : cartes) {
            if (joueur_sans_max_cartes == joueur1) {
                for (auto c2: cartes_joueur1) {
                    if (c2->getType() != "Clan") {
                        for (auto couleur : c2->CouleursPossibles()) {
                            for (auto force : c2->forcesPossibles()) {
                                //Faire chaque carte outs pour chaque possibilité
                                c2->setCouleurAuto(couleur);
                                c2->setForceAuto(force);
                                combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1], c2, nb_cartes_max);
                                if (combinaison_joueur1->getPuissance() > puissance_joueur_max_cartes) {

                                    for (auto c3: cartes_outs) {
                                        if (c3->getId() == c->getId()) {
                                            carte_deja_ajoute = true;
                                        }
                                    }
                                    if (!carte_deja_ajoute) {
                                        cartes_outs.push_back(c);
                                    }
                                    carte_deja_ajoute = false;

                                }
                            }
                        }
                    }
                    else {
                        combinaison_joueur1 = new Combinaison(cartes_joueur1[0], cartes_joueur1[1], c2, nb_cartes_max);
                        if (combinaison_joueur1->getPuissance() > puissance_joueur_max_cartes) {

                            for (auto c3: cartes_outs) {
                                if (c3->getId() == c->getId()) {
                                    carte_deja_ajoute = true;
                                }
                            }
                            if (!carte_deja_ajoute) {
                                cartes_outs.push_back(c);
                            }
                            carte_deja_ajoute = false;

                        }
                    }
                }
            }

            else {
                for (auto c2: cartes_joueur2) {
                    if (c2->getType() != "Clan") {
                        for (auto couleur : c2->CouleursPossibles()) {
                            for (auto force : c2->forcesPossibles()) {
                                //Faire chaque carte outs pour chaque possibilité
                                c2->setCouleurAuto(couleur);
                                c2->setForceAuto(force);
                                combinaison_joueur2 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1], c2, nb_cartes_max);
                                if (combinaison_joueur2->getPuissance() > puissance_joueur_max_cartes) {

                                    for (auto c3: cartes_outs) {
                                        if (c3->getId() == c->getId()) {
                                            carte_deja_ajoute = true;
                                        }
                                    }
                                    if (!carte_deja_ajoute) {
                                        cartes_outs.push_back(c);
                                    }
                                    carte_deja_ajoute = false;

                                }
                            }
                        }
                    }
                    else {
                        combinaison_joueur2 = new Combinaison(cartes_joueur2[0], cartes_joueur2[1], c2, nb_cartes_max);
                        if (combinaison_joueur2->getPuissance() > puissance_joueur_max_cartes) {

                            for (auto c3: cartes_outs) {
                                if (c3->getId() == c->getId()) {
                                    carte_deja_ajoute = true;
                                }
                            }
                            if (!carte_deja_ajoute) {
                                cartes_outs.push_back(c);
                            }
                            carte_deja_ajoute = false;

                        }
                    }
                }
            }
        }
    }

    else {
        cout << "il n'est pas possible de revendiquer" << endl;
        return 0;
    }




}