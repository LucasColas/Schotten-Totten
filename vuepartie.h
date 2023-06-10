//
// Created by lucas on 20/05/2023.
//

#ifndef SCHOTTEN_TOTTEN_VUEPARTIE_H
#define SCHOTTEN_TOTTEN_VUEPARTIE_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <string>
#include "Carte.h"
#include "Borne.h"
#include "Jeu.h"
#include "vuecarte.h"
#include "vueborne.h"
#include "vuepioche.h"
#include "vuedefausse.h"
class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;
class VueCarte;
class VueBorne;
class VuePioche;
class VuePartie : public QWidget {
Q_OBJECT
public:
    explicit VuePartie(string mode_, string variante_, int nb_p, int nb_joueurs_h, vector<string>& noms_j, QWidget *parent = nullptr);
    virtual ~VuePartie();
    void showInfo(const char* message);
    bool getInRuse() const {return inRuse;};
    std::string getWhatRuse() const {return whatRuse;};
    void setInRuse(bool b) {inRuse = b;};
    void setWhatRuse(string s);

private:
    Jeu *controller; // controleur de la partie
    QLabel* scoreLabel; // texte "Score"
    QLCDNumber* scoreDisplayer; // affichage du score
    QLabel* deckLabel; // texte "Pioche"
    QProgressBar* numberCardsDeckProgressBar; // progression de la pioche
    QHBoxLayout* informationsHeaderLayout;
    QGridLayout* firstCardsGridLayout; // grille des cartes du joueur en haut
    QGridLayout* bornesGridLayout; //grille des bornes
    QGridLayout* secondCardsGridLayout; //Grille des cartes du joueur en bas
    QGridLayout* playerCardsGridLayout; //Grille des cartes du joueur
    QHBoxLayout* rightLayout;
    QSpacerItem *spacer;
    QVBoxLayout* buttonLayout;
    QVBoxLayout* layer;
    vector<VueCarte*> vuecarteshaut; // adresses des objets VueCarte
    vector<VueCarte*> vuecartesbas;
    vector<VueCarte*> vuecartesjoueur;
    vector<VueBorne*> vuebornes;
    vector<VuePioche*> vuepioches;
    VueDefausse* vueDefausse;

    string mode;
    string variante;
    Carte* carte_selectionne;
    VueCarte* vueCarteSelectionne;
    bool carte_exception; //Permet de récupérer à une carte à un endroit où on n'aurait pas le droit de base. Utile pour les cartes ruses.
    bool carte_place;
    void changerJoueur();
    void clearvues();
    int nb_cartes_haut;
    void verif_bornes();

    bool inRuse; // Pour savoir si le jeu attend l'execution d'une carte ruse
    std::string whatRuse; // Pour quelle carte ruse

    // Pour effet chasseur de tete
    int aPiocher;
    int aDeposer

    //std::set<const Set::Carte*> selectedCards; // ensemble des cartes sélectionnées

    void updateVueCards();
    void verifPartie();


private slots:
    // slots qui gère les clics sur les cartes
    void onCardClicked(VueCarte* vc);
    void onPiocheClicked(VuePioche* p);
    void onBorneClicked(VueBorne* b);
    void onDefausseClicked(VueDefausse* p);

};
#endif //SCHOTTEN_TOTTEN_VUEPARTIE_H
