using namespace std;
#ifndef SCHOTTEN_TOTTEN_JEU_H
#define SCHOTTEN_TOTTEN_JEU_H
#include "Joueur.h"
#include "Affichage_console.h"
#include "Schotten_Totten.h"
#include "Pioche.h"
#include "defausse.h"
#include "Borne.h"
#include "Revendication.h"
class Jeu {
private:
    int nb_joueurs;
    int joueur_actuel;
    int nb_max_joueurs;
    vector<Joueur*> joueurs;
    string mode_jeu;
    string variante;
    vector<string> editions;
    int nb_parties;
    int nb_parties_jouees;
    int nb_joueurs_humains;
    string choix_IA;
    string choix_affichage;
    Affichage_console* affichageConsole;
    vector<string> variantes;
    Schotten_Totten* schottenTotten;
    Pioche* pioche;
    Pioche* pioche_tactique;
    Defausse* defausse;
    map<string, Pioche*> pioches;
    Revendication* revendication;
    vector<string> noms_joueurs;


public:

    Jeu(string mode,string v, int nb_p, int nb_joueurs_h, vector<string>& noms_j, int nb_max_j=2);
    void designe_premier_joueur();
    void setNb_joueurs_humains();
    void choix_jeu();
    void jouer_tour();
    void setAffichage(string affichage);
    void setChoix_IA();
    void creation_joueurs();
    void setNb_parties();
    void resume();
    void distribution_cartes();
    int partie_terminee();
    string getModeJeu() const {return mode_jeu;};
    string getVariante() const {return variante;};
    int getNbParties() const {return nb_parties;};
    int getNbPartiesJouees() const {return nb_parties_jouees;};
    int getJoueurActuel() const {return joueur_actuel;};
    Schotten_Totten& getSchottenTotten() {return *schottenTotten;};
    Joueur& getJoueur(int i) const {return *joueurs[i-1];};
    Pioche& getPioche(string nom) const {return *pioches.at(nom);};
    void choixPioche();
    int autreJoueur();
    bool verif();
    bool action_carte_ruse(Carte& carte);
    void changer_joueur();
    void revendication_borne(int i);
    bool gagnant();
    bool verifPioche(string pioche);
};
#endif //SCHOTTEN_TOTTEN_JEU_H
