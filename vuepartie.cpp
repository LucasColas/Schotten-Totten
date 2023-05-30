//
// Created by lucas on 20/05/2023.
//

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include <QKeyEvent>

#include "vuecarte.h"
#include "vuepartie.h"
#include "vueborne.h"
VuePartie::~VuePartie() = default; // Add virtual destructor definition

VuePartie::VuePartie(string mode_, string variante_, int nb_p, int nb_joueurs_h, vector<string>& noms_j, QWidget *parent) : QWidget(parent), vuecarteshaut(36, nullptr), vuecartesbas(36,
                                                                                                                                  nullptr), vuecartesjoueur(9,
                                                                                                                                                            nullptr), vuebornes(9,
                                                                                                                                                                                nullptr)
{
    setWindowTitle("Schotten Totten!");
    mode = mode_;
    variante = variante_;
    controller = new Jeu(mode, variante, nb_p, nb_joueurs_h, noms_j);
    nb_cartes_haut = 36;


    //numberCardsDeckProgressBar = new QProgressBar;
    //numberCardsDeckProgressBar->setRange(0, Set::Jeu::getInstance().getNbCartes());
    //numberCardsDeckProgressBar->setValue(controller.getPioche().getNbCartes());
    //numberCardsDeckProgressBar->setFixedHeight(30);

    //scoreDisplayer = new QLCDNumber;
    //scoreDisplayer->display(0);
    //scoreDisplayer->setFixedHeight(30);

    //informationsHeaderLayout = new QHBoxLayout;
    carte_selectionne = nullptr;
    vueCarteSelectionne = nullptr;
    firstCardsGridLayout = new QGridLayout;
    secondCardsGridLayout = new QGridLayout;
    bornesGridLayout = new QGridLayout;
    playerCardsGridLayout = new QGridLayout;
    layer = new QVBoxLayout;
    cout << "Création Grid Layout" << endl;
    //informationsHeaderLayout->addWidget(deckLabel);
    //informationsHeaderLayout->addWidget(numberCardsDeckProgressBar);
    //informationsHeaderLayout->addWidget(scoreLabel);
    //informationsHeaderLayout->addWidget(scoreDisplayer);
    int index = 0;
    //Cartes du haut
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 4; ++j) {
            vuecarteshaut[index] = new VueCarte;

            vuecarteshaut[index]->setBorne(index);

            vuecarteshaut[index]->setNbBorne(i);

            firstCardsGridLayout->addWidget(vuecarteshaut[index], j, i);

            connect(vuecarteshaut[index], SIGNAL(carteClicked(VueCarte*)), this, SLOT(onCardClicked(VueCarte*)));
            index++;

        }
    }
    //Bornes
    for (int i = 0; i < 9; i++) {
        vuebornes[i] = new VueBorne;
        bornesGridLayout->addWidget(vuebornes[i], 0, i);

        //connect(vuebornes[i], SIGNAL(carteClicked(VueCarte*)), this, SLOT(onCardClicked(VueCarte*)));

    }

    //Cartes du Bas
    index = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 4; j++) {
            vuecartesbas[index] = new VueCarte;
            vuecartesbas[index]->setBorne(index);

            vuecartesbas[index]->setNbBorne(i);

            secondCardsGridLayout->addWidget(vuecartesbas[index], j, i);

            connect(vuecartesbas[index], SIGNAL(carteClicked(VueCarte*)), this, SLOT(onCardClicked(VueCarte*)));
            index++;
        }
    }

    //Cartes du joueur

    for (int i = 0; i < 9; i++) {
        vuecartesjoueur[i] = new VueCarte;
        playerCardsGridLayout->addWidget(vuecartesjoueur[i], 9, i);

        connect(vuecartesjoueur[i], SIGNAL(carteClicked(VueCarte*)), this, SLOT(onCardClicked(VueCarte*)));
        index++;
    }
    //Pioches et défausse
    QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    // Buttons on the right
    buttonLayout = new QVBoxLayout;
    for (int i = 0; i < 3; ++i) {
        QPushButton *button = new QPushButton(QString("Button %1").arg(i));
        buttonLayout->addWidget(button);
    }
    updateVueCards();
    rightLayout = new QHBoxLayout;
    rightLayout->addLayout(buttonLayout);
    rightLayout->addSpacerItem(spacer);


    //layer->addLayout(informationsHeaderLayout);
    layer->addLayout(firstCardsGridLayout);
    layer->addLayout(bornesGridLayout);
    layer->addLayout(secondCardsGridLayout);
    layer->addLayout(playerCardsGridLayout);
    layer->addLayout(rightLayout);
    setLayout(layer);
    cout << "Constructeur terminé" << endl;
}


void VuePartie::onCardClicked(VueCarte *vc)
{
    //A faire : on clique sur une carte de sa main. Ensuite on clique sur un slot vide.

    if (!vc->cartePresente()) {
        cout << "carte non présente" << endl;
        if (carte_selectionne != nullptr) {
            //Si c'est une carte qui est deja sur une borne
            bool dejaPlace = false;
            for (int i = 0; i < vuecarteshaut.size() && !dejaPlace; i++) {
                if (carte_selectionne == &vuecarteshaut[i]->getCarte()) {
                    dejaPlace = true;
                }
            }
            for (int i = 0; i < vuecartesbas.size() && !dejaPlace; i++) {
                if (carte_selectionne == &vuecartesbas[i]->getCarte()) {
                    dejaPlace = true;
            vc->setCarte(*carte_selectionne);
            for (int i = 0; i < vuecartesjoueur.size(); i++) {

                if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                    cout << "i : " << i << endl;
                    controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);
                    if (variante == "normal") {
                        cout << "size pioche : " << controller->getPioche("pioche clan").sizePioche() << endl;
                        controller->getJoueur(controller->getJoueurActuel()).ajout_carte(&controller->getPioche("pioche clan").piocher_carte());
                        cout << "size pioche : " <<controller->getPioche("pioche clan").sizePioche() << endl;
                    }
                    controller->getSchottenTotten().getBorne(vc->getNbBorne()).ajout_Carte(carte_selectionne, controller->getJoueurActuel());
                    cout << "vecteur joueurs bornes : " << controller->getSchottenTotten().getBorne(vc->getNbBorne()).getCartes_joueur_2().size() << " " << controller->getSchottenTotten().getBorne(vc->getNbBorne()).getCartes_joueur_1().size() << endl;

                }
            }


            if (!dejaPlace) {
                //Si la vue est sur une borne revendiquee
                if (!vuebornes[vc->getBorne()]->getBorne().GetPossesseur()) {
                    vc->setCarte(*carte_selectionne);
                    for (int i = 0; i < vuecartesjoueur.size(); i++) {
                        if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                            cout << "i : " << i << endl;
                            controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i + 1);
                            if (variante == "normal") {
                                cout << "size pioche : " << controller->getPioche("pioche clan").sizePioche() << endl;
                                controller->getJoueur(controller->getJoueurActuel()).ajout_carte(
                                        &controller->getPioche("pioche clan").piocher_carte());
                                cout << "size pioche : " << controller->getPioche("pioche clan").sizePioche() << endl;
                            }
                        }
                    }
                    vueCarteSelectionne->setNoCarte();

            updateVueCards();
            changerJoueur();

            updateVueCards();


                    updateVueCards();
                }
            }
            cout << "La carte sélectionnée est déjà placée sur le plateau !" << endl;
        }

    }

    else if (vc->cartePresente()) {
        cout << "carte présente dans le slot" << endl;
        carte_selectionne = &vc->getCarte(); //On récupère la carte
        vueCarteSelectionne = vc;

    }
    update();
}

void VuePartie::changerJoueur() {
    for (int i = 0; i < vuecartesjoueur.size(); i++) {
        vuecartesjoueur[i]->setNoCarte();
    }
    if (controller->getJoueurActuel() == 1) {
        controller->setJoueurActuel(2);
        return;
    }

    controller->setJoueurActuel(1);

}


void VuePartie::clearvues() {
    for (int i = 0; i < vuecarteshaut.size(); i++) {
        vuecarteshaut[i]->setNoCarte();
    }

    for (int i = 0; i < vuecartesbas.size(); i++) {
        vuecartesbas[i]->setNoCarte();
    }

}

void VuePartie::updateVueCards() {
    //Mettre à jour les cartes du joueur actuel. Prendre les cartes depuis le controleur
    //
    //Mettre à jour les bornes par exemple.
    clearvues();
    for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
        vuebornes[i]->setBorne(controller->getSchottenTotten().getBorne(i));
    }


    if (controller->getJoueurActuel() == 1) {

        for (int i = 0; i < controller->getJoueur(1).getNbCartes(); i++) {
            vuecartesjoueur[i]->setCarte(*controller->getJoueur(1).getCartes()[i]);
        }

        //Le joueur 2 est en haut.
        for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
            for (int j = 0; j < controller->getSchottenTotten().getBorne(i).getCartes_joueur_2().size(); j++) {
                cout << "size borne  " << i << " : " << controller->getSchottenTotten().getBorne(i).getCartes_joueur_2().size();
                cout << "c : " << *controller->getSchottenTotten().getBorne(i).getCartes_joueur_2()[j] << endl;
                cout << "i*4+j :" << i*4 + j << endl;
                vuecarteshaut[i*4 + j]->setCarte(*controller->getSchottenTotten().getBorne(i).getCartes_joueur_2()[j]);
            }
        }

        for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
            for (int j = 0; j < controller->getSchottenTotten().getBorne(i).getCartes_joueur_1().size(); j++) {
                vuecartesbas[i*4 + j]->setCarte(*controller->getSchottenTotten().getBorne(i).getCartes_joueur_1()[j]);
            }
        }
    }

    if (controller->getJoueurActuel() == 2) {

        for (int i = 0; i < controller->getJoueur(2).getNbCartes(); i++) {
            vuecartesjoueur[i]->setCarte(*controller->getJoueur(2).getCartes()[i]);
        }
        //Les cartes du joueur 1 sont en haut.
        for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
            for (int j = 0; j < controller->getSchottenTotten().getBorne(i).getCartes_joueur_1().size(); j++) {
                cout << "size borne " << i << " : " << controller->getSchottenTotten().getBorne(i).getCartes_joueur_1().size();
                cout << "c : " << *controller->getSchottenTotten().getBorne(i).getCartes_joueur_1()[j] << endl;
                cout << "i*4+j :" << i*4 + j << endl;
                vuecarteshaut[i*4 + j]->setCarte(*controller->getSchottenTotten().getBorne(i).getCartes_joueur_1()[j]);

            }
        }

        for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
            for (int j = 0; j < controller->getSchottenTotten().getBorne(i).getCartes_joueur_2().size(); j++) {
                vuecartesbas[i*4 + j]->setCarte(*controller->getSchottenTotten().getBorne(i).getCartes_joueur_2()[j]);
            }
        }
    }



}
