//
// Created by lucas on 23/03/2023.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;
#ifndef SCHOTTEN_TOTTEN_CARTE_H
#define SCHOTTEN_TOTTEN_CARTE_H

enum class Couleur {Rouge, Vert, Bleu, Dore, Violet, Marron};
class Carte {
protected:
    string id; //un id pour chaque carte. Peut servir pour retrouver une carte
};

class Carte_clan : public Carte {
private:
    Couleur couleur;
    int force;
public:
    Carte_clan(string id, Couleur couleur, int force);
    Couleur get_couleur();
    int get_force();


};

class Borne : public Carte {
private:
    int regle;
    int nb_max_cartes;
    int possesseur;
    vector<Carte> cartes_joueur_1;
    vector<Carte> cartes_joueur_2;
    vector<Carte> carte_dessus;
    queue<Carte> historique;
public:
    Borne();
};

class Carte_tactique : public Carte {
private:
    string type; //Pour savoir le type de carte tactique.
public:
    Carte_tactique();
    void capacite();
    string getType();
    void setType();

};

class Carte_Combat : public Carte_tactique {
public:
    Carte_Combat();
    void choix_borne();
};

class Carte_Elite : public Carte_tactique {
private:
    Couleur couleur;
    int force;
    vector<Couleur> couleurs_possibles;
    vector<int> force_possible;
public:
    Carte_Elite();
    void setCouleur();
    void setForce();

};

class Carte_Ruse : public Carte_tactique {
public:
    Carte_Ruse();

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
