

#include "Carte.h"

#ifndef COMBINAISON_H
#define COMBINAISON_H
class Combinaison{
    Carte* c1;
    Carte* c2;
    Carte* c3;
    Carte* c4;
    int nb_cartes;
    int Puissance;
    int somme;

public:
    //const Carte& getCarte1() const { return *c1; }
    //const Carte& getCarte2() const { return *c2; }
    //const Carte& getCarte3() const { return *c3; }
    Combinaison(Carte* c1_, Carte* c2_, Carte* c3_, int nb_c) : c1(c1_), c2(c2_), c3(c3_), nb_cartes(nb_c) {};
    Combinaison(Carte* c1_, Carte* c2_, Carte* c3_, Carte* c4_, int nb_c) : c1(c1_), c2(c2_), c3(c3_), c4(c4_),nb_cartes(nb_c) {};

    
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

