//
// Created by lucas on 06/05/2023.
//
#include "Revendication.h"
#include "Carte.h"
#include "algorithm"
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

void Revendication::generer_combi(vector<Carte*>& cartes_adversaire, vector<Carte*>& cartes_) {
    cout << "generer combi" << endl;
    cout << "cartes adversaire" << cartes_adversaire.size();
    cout << "cartes" << cartes_.size();
    for (int i = 0; i < cartes_.size(); i++) {
        if (cartes_adversaire.size() <= 1) {
            for (int j = 0; j < cartes_.size(); j++) {
                if (cartes_adversaire.empty()) {
                    for (int k = 0; k < cartes_.size(); k++) {
                        if (i != k && i != j && j != k) {
                            //cout << "combi generee" << endl;
                            combinaisons.push_back(new Combinaison(cartes_[i], cartes_[j], cartes_[k], 3));
                        }
                    }
                }
                if (!cartes_adversaire.empty() && i != j && cartes_[i]->getId() != cartes_adversaire[0]->getId() && cartes_[j]->getId() != cartes_adversaire[0]->getId()) {
                    combinaisons.push_back(new Combinaison(cartes_[i], cartes_[j], cartes_adversaire[0], 3));
                }
            }
        }

        else {
            cout << "cas adversaire a 2 cartes" << endl;
            if (cartes_adversaire.size() >= 2 && cartes_[i]->getId() != cartes_adversaire[0]->getId() && cartes_[i]->getId() != cartes_adversaire[1]->getId()) {
                combinaisons.push_back(new Combinaison(cartes_[i], cartes_adversaire[0], cartes_adversaire[1], 3));
            }

        }

    }
    cout << "fin generation" << endl;
    for (int i = 0; i < combinaisons.size(); i++) {
        //cout << "combinaison cartes : " << combinaisons[i]->getC1() << combinaisons[i]->getC2() << combinaisons[i]->getC3();
        //cout << endl;
    }
}

bool Revendication::supprimerCombi(vector<Borne*>& bornes,Combinaison* c) {
    vector<bool> cartes_t = {false, false, false};
    for (int j = 0; j < bornes.size(); j++) {
        for (int k = 0; k < bornes[j]->getCartes_joueur_1().size(); k++) {
            for (int l = 0; l < c->getCartesCombi().size(); l++) {
                if (bornes[j]->getCartes_joueur_1()[k]->getId() == c->getCartesCombi()[l]->getId()) {
                    //cout << bornes[j]->getCartes_joueur_1()[k]->getId() << " " << c->getCartesCombi()[l]->getId() << endl;
                    //cout << "combinaison cartes : " << c->getC1() << c->getC2() << c->getC3();
                    cartes_t[l] = true;

                }
            }


        }
        for (int k = 0; k < bornes[j]->getCartes_joueur_2().size(); k++) {
            for (int l = 0; l < c->getCartesCombi().size(); l++) {
                if (bornes[j]->getCartes_joueur_2()[k]->getId() == c->getCartesCombi()[l]->getId()) {
                    //cout << bornes[j]->getCartes_joueur_2()[k]->getId() << " " << c->getCartesCombi()[l]->getId() << endl;
                    cartes_t[l] = true;
                }
            }

        }
    }
    //cout << "combinaison cartes : " << c->getC1() << c->getC2() << c->getC3();
    for (auto i : cartes_t) {
        if (!i) {
            return false;
        }
    }
    return true;
}
bool Revendication::PotentielleCombinaison(vector<Borne*>& bornes, vector<Carte*>& cartes, Combinaison* combinaison, vector<Carte*>& cartes_adversaire) {
    combinaisons.clear();
    cout << "Potentielle Combinaison" << endl;
    generer_combi(cartes_adversaire, cartes);
    int nb_combi_sup = 0;
    vector<Combinaison*> combi_sup;
    vector<int> index_combi_supp;
    int carte_combi_trouve = false;
    int MaxPuissance = combinaison->getMaxPuissance();
    cout << "MaxPuissance" << MaxPuissance << endl;
    for (int i = 0; i < combinaisons.size(); i++) {
        //cout << "Combi Max Puissance" << combinaisons[i]->getMaxPuissance() << endl;
        if (combinaisons[i]->getMaxPuissance() > MaxPuissance) {
            combi_sup.push_back(combinaisons[i]);
        }
    }
    //cout << "size combi sup " << combi_sup.size() << endl;

    for (int i = 0; i < combi_sup.size(); i++) {
        //cout << "suppri combi : " << supprimerCombi(bornes, combi_sup[i]) << endl;
        if (supprimerCombi(bornes, combi_sup[i])) {
            index_combi_supp.push_back(i);
        }
    }


    cout << "combi sup size" << combi_sup.size() << endl;
    cout << "index combi supp " << index_combi_supp.size() << endl;
    if (combi_sup.size() == index_combi_supp.size()) {
        return false;
    }
    return true;
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

int Revendication::Revendiquer_sans_max_cartes(vector<Carte*>& cartes, vector<Borne*>& bornes) {
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


        for (auto b : bornes) {
            for (auto c1 : b->getCartes_joueur_1()) {
                for (auto c : cartes_outs) {
                    if (c1->get_couleur() == c->get_couleur() && c1->get_force() == c->get_force()) {
                        auto it = find(cartes_outs.begin(), cartes_outs.end(), c);
                        if (it != cartes_outs.end()) {
                            cartes_outs.erase(it);
                            break;
                        }
                    }
                }

            }
        }
        if (cartes_outs.size() > 0) {
            cout << "pas encore possible de revendiquer" << endl;
            return 0;
        }

    }

    else {
        cout << "il n'est pas possible de revendiquer" << endl;
        return 0;
    }




}