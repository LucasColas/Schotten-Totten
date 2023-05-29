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
#include "Carte.h"
#include "Borne.h"
#include "Jeu.h"
#include "vuecarte.h"
#include "vueborne.h"
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
class VuePartie : public QWidget {
Q_OBJECT
public:
    explicit VuePartie(string mode_, string variante_, int nb_p, int nb_joueurs_h, vector<string>& noms_j, QWidget *parent = nullptr);
    virtual ~VuePartie();

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

    string mode;
    string variante;
    Carte* carte_selectionne;
    VueCarte* vueCarteSelectionne;
    void changerJoueur();
    void clearvues();
    int nb_cartes_haut;

    //std::set<const Set::Carte*> selectedCards; // ensemble des cartes sélectionnées

    void updateVueCards();
    void showWarning(const char* message);
    void addNewCardIfDeckNotEmpty();

    void clearSelectedCardsIfInvalidSET();



    void checkIfValidSETAndClearSelectedCards();

private slots:
    // slots qui gère les clics sur les cartes
    void onCardClicked(VueCarte* vc);
    //void onPiocheClicked(VuePioche* p);
    //void onDefausseClicked(VueDefausse* p);
};
#endif //SCHOTTEN_TOTTEN_VUEPARTIE_H
