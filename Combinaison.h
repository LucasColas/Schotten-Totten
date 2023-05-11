

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
    int MaxPuissance;
    vector<Carte*> cartes_combi;
    int somme;
    int MaxSomme;

public:
    //const Carte& getCarte1() const { return *c1; }
    //const Carte& getCarte2() const { return *c2; }
    //const Carte& getCarte3() const { return *c3; }
    Combinaison(Carte* c1_, Carte* c2_, Carte* c3_, int nb_c);
    Combinaison(Carte* c1_, Carte* c2_, Carte* c3_, Carte* c4_, int nb_c);

    
    const int getPuissance() const {return Puissance;}
    vector<Carte*> getCartesCombi() {return cartes_combi;};
    void setCartes(Carte* c1_, Carte* c2_, Carte* c3_);

    bool estUneCouleur();
    bool estUneSuite();
    bool estUnBrelan();
    bool estUneSuiteCouleur();
    void sommeSuite();
    int getSommeSuite() const {return somme;};

    void PuissanceCombinaison();
    int getMaxPuissance();
    int getMaxSomme() const {return MaxSomme;};

    void DonnerCombinaison();
};
#endif // COMBINAISON_H

