#include "Combinaison.h"
#include <algorithm>

using namespace std;

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

void Combinaison::PuissanceCombinaison(){
    int p=c1->get_force() + c2->get_force() + c3->get_force();
    if (nb_cartes==4) {
        p = p + c4->get_force();
    }

    if (estUneSuiteCouleur()) p=p+10000;
    if (estUnBrelan()) p=p+10000;
    if (estUneCouleur()) p=p+1000;
    if (estUneSuite()) p=p+100;

    Puissance=p;
}

void Combinaison::sommeSuite() {
    //Methode pour quand 2 suites sont de même puissance.
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