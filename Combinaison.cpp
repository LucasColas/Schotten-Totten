#include "Combinaison.h"



bool Combinaison::estUneCouleur(){
    Couleur C1= c1->get_couleur();
    Couleur C2= c2->get_couleur();
    Couleur C3= c3->get_couleur();

    return (C1==C2 && C2==C3);
}

bool Combinaison::estUneSuite(){
    int v1=c1->get_force();
    int v2=c2->get_force();
    int v3=c3->get_force();

    return  (v1*2==v2+v3-2 || v2*2==v1+v3-2 || v3*2== v1+v2-2);
}

bool Combinaison::estUnBrelan(){
    int v1=c1->get_force();
    int v2=c2->get_force();
    int v3=c3->get_force();

    return (v1==v2 && v2==v3);
}

bool Combinaison::estUneSuiteCouleur(){
    return (estUneCouleur() && estUneSuite());
}

void Combinaison::PuissanceCombinaison(){
    int p=c1->get_force() + c2->get_force() + c3->get_force();

    if (estUneSuiteCouleur()) p=p+10000;
    if (estUnBrelan()) p=p+10000;
    if (estUneCouleur()) p=p+1000;
    if (estUneSuite()) p=p+100;

    Puissance=p;
}