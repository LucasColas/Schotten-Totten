//
// Created by lucas on 23/03/2023.
//
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#ifndef SCHOTTEN_TOTTEN_CARTE_H
#define SCHOTTEN_TOTTEN_CARTE_H

enum class Couleur {Rouge, Vert, Bleu, Dore, Violet, Marron, NC}; //NC est utilisée pour des cartes tactique qui n'ont pas encore de couleur
string toString(Couleur c);

ostream& operator<<(ostream& f, Couleur c);

class SetException {
public:
    SetException(const string& i) : info(i) {}
    string getInfo() const { return info; }
private:
    string info;
};



class Carte {
protected:
    string id; //un id pour chaque carte. Peut servir pour retrouver une carte
};

class Carte_clan : public Carte {
private:
    Couleur couleur;
    int force;
public:
    Carte_clan(string id_, Couleur couleur_, int force_);
    Couleur get_couleur() const { return couleur;};
    int get_force() const { return force;};

    friend ostream& operator<<(ostream& f, const Carte_clan& c);

};

class Borne : public Carte {
private:
    int regle;
    int nb_max_cartes;
    int possesseur;
    vector<Carte*> cartes_joueur_1;
    vector<Carte*> cartes_joueur_2;
    vector<Carte*> carte_dessus;
    map<Carte*, string> historique; //pour savoir qui a posé la troisième carte en premier
public:
    Borne(string id_, int r=0, int nb_cartes=3, int possesseur=0);
    int getRegle() const { return regle;};
    int getNbMaxCartes() const { return nb_max_cartes;};
    int GetPossesseur() const {return possesseur;};
    vector<Carte*> getCartes_joueur_1() {return cartes_joueur_1;};
    vector<Carte*> getCartes_joueur_2() {return cartes_joueur_2;};

    friend ostream& operator<<(ostream& f, const Borne& b);



};

class Carte_tactique : public Carte {
//Pour savoir le type de carte tactique (Combat, Elite, etc.).
protected:
    string type;
public:
    Carte_tactique(string id_, string t);
    void capacite();
    string getType() const { return type;};
    void setType();

};

class Carte_Combat : public Carte_tactique {
public:

    void choix_borne();
};

class Carte_Elite : public Carte_tactique {
private:
    Couleur couleur;
    int force;
    vector<Couleur> couleurs_possibles;
    vector<int> force_possible;
public:
    Carte_Elite(string t, string id_, int f, Couleur c);
    void setCouleur();
    void setForce();

};

class Carte_Ruse : public Carte_tactique {
public:

};

class Carte_chasseur_de_tete : public Carte_Ruse {

};

class Carte_Stratege : public Carte_Ruse {

};

class Carte_Banshee : public Carte_Ruse {

};

class Carte_Traitre : public Carte_Ruse {

};

#endif //SCHOTTEN_TOTTEN_CARTE_H
