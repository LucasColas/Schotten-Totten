

#include "Carte.h"

#ifndef COMBINAISON_H
#define COMBINAISON_H
class Combinaison{
    Carte* c1;
    Carte* c2;
    Carte* c3;
    int Puissance;
    int somme;

public:
    //const Carte& getCarte1() const { return *c1; }
    //const Carte& getCarte2() const { return *c2; }
    //const Carte& getCarte3() const { return *c3; }
    Combinaison(Carte* c1_, Carte* c2_, Carte* c3_);
    
    const int getPuissance() const {return Puissance;}
    void setCartes(Carte* c1_, Carte* c2_, Carte* c3_);

    bool estUneCouleur();
    bool estUneSuite();
    bool estUnBrelan();
    bool estUneSuiteCouleur();
    void sommeSuite();
    int getSommeSuite() const {return somme;};

    void PuissanceCombinaison();

    void DonnerCombinaison();
};
#endif // COMBINAISON_H

