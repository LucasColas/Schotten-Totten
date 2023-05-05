

#include "Carte.h"


class Combinaison{
    const Carte_clan* c1;
    const Carte_clan* c2;
    const Carte_clan* c3;
    int Puissance=0;

public:
    //const Carte& getCarte1() const { return *c1; }
    //const Carte& getCarte2() const { return *c2; }
    //const Carte& getCarte3() const { return *c3; }
    
    const int getPuissance() const {return Puissance;}

    bool estUneCouleur();
    bool estUneSuite();
    bool estUnBrelan();
    bool estUneSuiteCouleur();

    void PuissanceCombinaison();
};
