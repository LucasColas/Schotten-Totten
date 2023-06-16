#include "Combinaison.h"
#include "Carte.h"
#include <algorithm>
#include <iostream>
using namespace std;
Combinaison::Combinaison(Carte *c1_, Carte *c2_, Carte *c3_, int nb_c) {
    cartes_combi.push_back(c1_);
    cartes_combi.push_back(c2_);
    cartes_combi.push_back(c3_);
    c1 = c1_;
    c2 = c2_;
    c3 = c3_;
}
Combinaison::Combinaison(Carte *c1_, Carte *c2_, Carte *c3_, Carte *c4_, int nb_c) {
    cartes_combi.push_back(c1_);
    cartes_combi.push_back(c2_);
    cartes_combi.push_back(c3_);
    cartes_combi.push_back(c3_);
    c1 = c1_;
    c2 = c2_;
    c3 = c3_;
    c4 = c4_;
}
bool Combinaison::estUneCouleur(){
    Couleur C1= c1->get_couleur();
    Couleur C2= c2->get_couleur();
    Couleur C3= c3->get_couleur();
    if (nb_cartes == 4) {
        Couleur C4 = c4->get_couleur();
        return (C1==C2 && C2==C3 && C3==C4);
    }
    return (C1==C2 && C2==C3);
}

bool Combinaison::estUneSuite(){
    if (nb_cartes == 4) {
        Carte* cartes[] = { c1, c2, c3, c4 };
        sort(cartes, cartes + nb_cartes, [](Carte* a, Carte* b) { return a->get_force() < b->get_force(); });

        // Vérifier si les valeurs des cartes sont consécutives
        return (cartes[0]->get_force() == cartes[1]->get_force() - 1) && (cartes[1]->get_force() == cartes[2]->get_force() - 1) && (cartes[2]->get_force() == cartes[3]->get_force());
    }
    Carte* cartes[] = { c1, c2, c3 };
    sort(cartes, cartes + 3, [](Carte* a, Carte* b) { return a->get_force() < b->get_force(); });

    // Vérifier si les valeurs des cartes sont consécutives
    return (cartes[0]->get_force() == cartes[1]->get_force() - 1) && (cartes[1]->get_force() == cartes[2]->get_force() - 1);

}

bool Combinaison::estUnBrelan(){
    int v1=c1->get_force();
    int v2=c2->get_force();
    int v3=c3->get_force();
    if (nb_cartes == 4) {
        int v4 = c4->get_force();
        return (v1==v2 && v2==v3 && v3 == v4);
    }

    return (v1==v2 && v2==v3);
}

bool Combinaison::estUneSuiteCouleur(){
    return (estUneCouleur() && estUneSuite());
}
int Combinaison::getMaxPuissance() {

    MaxPuissance = 0;
    MaxSomme = 0;

    if (c1->getType() != "Clan" && c2->getType() != "Clan" && c3->getType() != "Clan") {
        for (auto couleur : c1->CouleursPossibles()) {
            for (auto force : c1->forcesPossibles()) {
                for (auto couleur2: c2->CouleursPossibles()) {
                    for (auto force2: c2->forcesPossibles()) {
                        for (auto couleur3: c3->CouleursPossibles()) {
                            for (auto force3 : c3->forcesPossibles()) {
                                c1->setCouleurAuto(couleur);
                                c1->setForceAuto(force);
                                c2->setForceAuto(force2);
                                c2->setCouleurAuto(couleur2);
                                c3->setCouleurAuto(couleur3);
                                c3->setForceAuto(force3);
                                PuissanceCombinaison();

                                if (MaxPuissance < Puissance) {
                                    MaxPuissance = Puissance;

                                }
                                sommeSuite();
                                MaxSomme = max(MaxSomme, somme);
                            }
                        }
                    }
                }
            }
        }
        return MaxPuissance;
    }

    if (c1->getType() != "Clan" && c2->getType() != "Clan") {
        for (auto couleur : c1->CouleursPossibles()) {
            for (auto force : c1->forcesPossibles()) {
                for (auto couleur2: c2->CouleursPossibles()) {
                    for (auto force2: c2->forcesPossibles()) {

                        c1->setCouleurAuto(couleur);
                        c1->setForceAuto(force);
                        c2->setForceAuto(force2);
                        c2->setCouleurAuto(couleur2);
                        PuissanceCombinaison();
                        if (MaxPuissance < Puissance) {
                            MaxPuissance = Puissance;

                        }
                        sommeSuite();
                        MaxSomme = max(MaxSomme, somme);

                    }
                }
            }
        }
        return MaxPuissance;
    }

    if (c1->getType() != "Clan" && c3->getType() != "Clan") {
        for (auto couleur : c1->CouleursPossibles()) {
            for (auto force : c1->forcesPossibles()) {
                for (auto couleur3: c3->CouleursPossibles()) {
                    for (auto force3 : c3->forcesPossibles()) {
                        c1->setCouleurAuto(couleur);
                        c1->setForceAuto(force);
                        c3->setCouleurAuto(couleur3);
                        c3->setForceAuto(force3);
                        PuissanceCombinaison();
                        if (MaxPuissance < Puissance) {
                            MaxPuissance = Puissance;

                        }
                        sommeSuite();
                        MaxSomme = max(MaxSomme, somme);
                    }
                }
            }
        }
        return MaxPuissance;
    }

    if (c2->getType() != "Clan" && c3->getType() != "Clan") {
        cout << "on a 2 carte tactique" << endl;
        for (auto couleur2: c2->CouleursPossibles()) {
            for (auto force2: c2->forcesPossibles()) {
                for (auto couleur3: c3->CouleursPossibles()) {
                    for (auto force3 : c3->forcesPossibles()) {

                        c2->setForceAuto(force2);
                        c2->setCouleurAuto(couleur2);
                        c3->setCouleurAuto(couleur3);
                        c3->setForceAuto(force3);
                        PuissanceCombinaison();
                        if (MaxPuissance < Puissance) {
                            MaxPuissance = Puissance;

                        }
                        sommeSuite();
                        MaxSomme = max(MaxSomme, somme);

                    }
                }
            }
        }
        return MaxPuissance;
    }

    cout << "cartes combi size : " << cartes_combi.size() << endl;

    for (int i = 0; i < cartes_combi.size(); i++) {
        cout << "carte combi : " << *cartes_combi[i] << endl;
        //cout << "on a une carte tactique" << endl;
        //cout << cartes_combi[i]->getType() << endl;
        if (cartes_combi[i]->getType() != "Clan") {
            for (auto force: cartes_combi[i]->forcesPossibles()) {
                for (auto couleur: cartes_combi[i]->CouleursPossibles()) {
                    cout << "essai puissance" << endl;
                    cartes_combi[i]->setForceAuto(force);
                    cartes_combi[i]->setCouleurAuto(couleur);
                    PuissanceCombinaison();
                    MaxPuissance = max(Puissance, MaxPuissance);
                    sommeSuite();
                    MaxSomme = max(MaxSomme, somme);
                }
            }
        }
    }
    if (c1->getType() == "Clan" && c2->getType() == "Clan" && c3->getType() == "Clan") {
        PuissanceCombinaison();
        return Puissance;
    }

    return MaxPuissance;


}

void Combinaison::PuissanceCombinaison(){

    int p=c1->get_force() + c2->get_force() + c3->get_force();
    if (nb_cartes==4) {
        p = p + c4->get_force();
    }

    if (estUneSuiteCouleur()) p=p+100000;
    if (estUnBrelan()) p=p+10000;
    if (estUneCouleur()) p=p+1000;
    if (estUneSuite()) p=p+100;

    Puissance=p;
}

void Combinaison::sommeSuite() {
    //Methode pour quand 2 combinaisons sont de même puissance.
    somme = c1->get_force() + c2->get_force() + c3->get_force();
    if (nb_cartes == 4) {
        somme = somme + c4->get_force();
    }
}

void Combinaison::setCartes(Carte *c1_, Carte *c2_, Carte *c3_) {
    c1 = c1_;
    c2 = c2_;
    c3 = c3_;
}