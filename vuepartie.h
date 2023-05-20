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
class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;
class VueCarte;
class VuePartie : public QWidget {
Q_OBJECT
public:
    explicit VuePartie(QWidget *parent = nullptr);
    virtual ~VuePartie();
private:
    Jeu *controller; // controleur de la partie
    QLabel* scoreLabel; // texte "Score"
    QLCDNumber* scoreDisplayer; // affichage du score
    QLabel* deckLabel; // texte "Pioche"
    QProgressBar* numberCardsDeckProgressBar; // progression de la pioche
    QHBoxLayout* informationsHeaderLayout;
    QGridLayout* cardsGridLayout; // grille des cartes
    QVBoxLayout* layer;
    vector<VueCarte*> vuecartes; // adresses des objets VueCarte
    //std::set<const Set::Carte*> selectedCards; // ensemble des cartes sélectionnées
    int userScore=0; // score courant (nb de sets trouvés)

    void updateVueCards();
    void showWarning(const char* message);
    void addNewCardIfDeckNotEmpty();

    void clearSelectedCardsIfInvalidSET();



    void checkIfValidSETAndClearSelectedCards();

private slots:
    // slots qui gère les clics sur les cartes
    void onCardClicked(VueCarte* vc);
};
#endif //SCHOTTEN_TOTTEN_VUEPARTIE_H
