

#include "Carte.h"


class Combinaison{
    const Carte_clan* c1;
    const Carte_clan* c2;
    const Carte_clan* c3;
    const Carte_clan* c4;

    int Puissance=0;
    int nb_carte;

public:
    const Carte_clan& getCarte1() const { return *c1; }
    const Carte_clan& getCarte2() const { return *c2; }
    const Carte_clan& getCarte3() const { return *c3; }
    const Carte_clan& getCarte4() const { return *c4; }
    
    Combinaison(const Carte_clan* u, const Carte_clan* d, const Carte_clan* t): nb_carte(3), c1(u), c2(d), c3(t) {}
    Combinaison(const Carte_clan* u, const Carte_clan* d, const Carte_clan* t, const Carte_clan* q): nb_carte(4), c1(u), c2(d), c3(t), c4(q) {}

    
    const int getPuissance() const {return Puissance;}

    bool estUneCouleur3();
    bool estUneCouleur4();

    bool estUneSuite3();
    bool estUneSuite4();

    bool estUnBrelan3();
    bool estUnBrelan4();

    bool estUneSuiteCouleur3();
    bool estUneSuiteCouleur4();

    void PuissanceCombinaison();
};
