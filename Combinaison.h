

#include "Carte.h"


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
    Combinaison(Carte* c1_, Carte* c2_, Carte* c3_) : c1(c1_), c2(c2_), c3(c3_), Puissance(0) {};
    
    const int getPuissance() const {return Puissance;}

    bool estUneCouleur();
    bool estUneSuite();
    bool estUnBrelan();
    bool estUneSuiteCouleur();
    int sommeSuite();

    void PuissanceCombinaison();

    void DonnerCombinaison();
};


