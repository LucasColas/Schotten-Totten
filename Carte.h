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
public:
    virtual Couleur get_couleur() const { throw "erreur pas de couleur";};
    virtual int get_force() const { throw "erreur pas de force.";};
    virtual int getNb_cartes() {throw "pas de nombre de cartes";};
    virtual string getType() const {throw "pas de type";};
    virtual int getRegle() const {throw "pas de regle";};
    virtual bool setCouleur() {throw "pas de set";};
    virtual bool setForce() {throw "pas de set";};
    string getId() const {return id;};

    friend ostream& operator<<(ostream& f, const Carte&);
};

class Carte_clan : public Carte {
private:
    Couleur couleur;
    int force;
    string type;
public:
    Carte_clan(string id_, Couleur couleur_, int force_, string t);
    Couleur get_couleur() const override { return couleur;};
    int get_force() const override { return force;};
    string getType() const override {return type;};

    friend ostream& operator<<(ostream& f, const Carte_clan& c);

};



class Carte_tactique : public Carte {
//Pour savoir le type de carte tactique (Combat, Elite, etc.).
protected:
    string type;
    int force;
    Couleur couleur;
public:
    Carte_tactique(string id_, string t);
    void capacite();
    string getType() const override { return type;};
    Couleur get_couleur() const override { return couleur;};
    int get_force() const override { return force;};
    void setType();

    friend ostream& operator<<(ostream& f, const Carte_tactique& c);

};

class Carte_Combat : public Carte_tactique {
private:
    int regle;
public:
    Carte_Combat(string t, string id_, int r);
    int getRegle() const override {return regle;};
    //void choix_borne();
    friend ostream& operator<<(ostream& f, const Carte_Combat& c);
};

class Carte_Elite : public Carte_tactique {
private:
    Couleur couleur;
    int force;
    initializer_list<Couleur> couleurs_possibles;
    vector<int> forces_possibles;

public:
    Carte_Elite(string t, string id_, int f, Couleur c);
    bool setCouleur() override;
    bool setForce() override;
    friend ostream& operator<<(ostream& f, const Carte_Elite& c);

};

class Carte_Ruse : public Carte_tactique {
public:
    Carte_Ruse(string t, string id_);
    friend ostream& operator<<(ostream& f, const Carte_Ruse& c);

};

class Carte_chasseur_de_tete : public Carte_Ruse {
private:
    int nb_cartes;
public:
    Carte_chasseur_de_tete(string t, string id_, int nb=3);
    int getNb_cartes() override {return nb_cartes;};
    void proposition();
    friend ostream& operator<<(ostream& f, const Carte_chasseur_de_tete& c);

};

class Carte_Stratege : public Carte_Ruse {
public:
    Carte_Stratege(string t, string id_);
    friend ostream& operator<<(ostream& f, const Carte_Stratege& c);

};

class Carte_Banshee : public Carte_Ruse {
public:
    Carte_Banshee(string t, string id_);
    friend ostream& operator<<(ostream& f, const Carte_Banshee& c);

};

class Carte_Traitre : public Carte_Ruse {
public:
    Carte_Traitre(string t, string id_);
    friend ostream& operator<<(ostream& f, const Carte_Traitre& c);

};


#endif //SCHOTTEN_TOTTEN_CARTE_H
