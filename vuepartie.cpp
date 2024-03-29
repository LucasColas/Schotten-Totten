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
#include "vuepioche.h"
#include <string>
using namespace std;
VuePartie::~VuePartie() = default; // Add virtual destructor definition

VuePartie::VuePartie(string mode_, string variante_, int nb_p, int nb_joueurs_h, vector<string>& noms_j, QWidget *parent) : QWidget(parent), vuecarteshaut(36, nullptr), vuecartesbas(36,
                                                                                                                                  nullptr), vuecartesjoueur(9,
                                                                                                                                                            nullptr), vuebornes(9,
                                                                                                                                                                                nullptr), vuepioches(2,
                                                                                                                                                                                                     nullptr)
{
    setWindowTitle("Schotten Totten!");
    mode = mode_;
    variante = variante_;
    controller = new Jeu(mode, variante, nb_p, nb_joueurs_h, noms_j);
    nb_cartes_haut = 36;
    carte_place = false;
    carte_exception = false;
    carte_stratege = false;
    carte_banshee = false;
    carte_chasseur_de_tete = false;
    compte_pioche = 0;
    cartes_choisies = 0;

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
            vuecarteshaut[index]->setNbBorne(i);
            firstCardsGridLayout->addWidget(vuecarteshaut[index], j, i);

            connect(vuecarteshaut[index], SIGNAL(carteClicked(VueCarte*)), this, SLOT(onCardClicked(VueCarte*)));
            index++;

        }
    }
    //Bornes
    for (int i = 0; i < 9; i++) {
        vuebornes[i] = new VueBorne(i);
        bornesGridLayout->addWidget(vuebornes[i], 0, i);

        connect(vuebornes[i], SIGNAL(BorneClicked(VueBorne *)), this, SLOT(onBorneClicked(VueBorne *)));

    }

    //Cartes du Bas
    index = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 4; j++) {
            vuecartesbas[index] = new VueCarte;
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

    // Pioches et défausse

    if (variante == "normal") {
        buttonLayout = new QVBoxLayout;
        vuepioches[0] = new VuePioche("pioche clan");
        connect(vuepioches[0], SIGNAL(PiocheClicked(VuePioche*)), this, SLOT(onPiocheClicked(VuePioche *)));

        buttonLayout->addWidget(vuepioches[0]);

    }

    if (variante=="tactique"){
        buttonLayout = new QVBoxLayout;
        vuepioches[0] = new VuePioche("pioche clan");
        connect(vuepioches[0], SIGNAL(PiocheClicked(VuePioche*)), this, SLOT(onPiocheClicked(VuePioche *)));
        vuepioches[1] = new VuePioche("pioche tactique");
        connect(vuepioches[1], SIGNAL(PiocheClicked(VuePioche*)), this, SLOT(onPiocheClicked(VuePioche *)));
        buttonLayout->addWidget(vuepioches[0]);
        buttonLayout->addWidget(vuepioches[1]);
        vueDefausse = new VueDefausse();
        connect(vueDefausse, SIGNAL(defausseClicked(VueDefausse*)), this, SLOT(onDefausseClicked(VueDefausse *)));
        buttonLayout->addWidget(vueDefausse);
    }
    /*for (int i = 0; i < 2; ++i) {

        QPushButton *button = new QPushButton(QString("Button %1").arg(i));
        buttonLayout->addWidget(button);
    }*/
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

    if (!vc->cartePresente()) {


        if (carte_selectionne != nullptr && carte_stratege) {
            cout << "Carte statege select" << endl;
            //Cas carte stratege selectionnee auparavant
            for (int i = 0; i < vuecartesbas.size(); i++) {
                if (carte_selectionne == &vuecartesbas[i]->getCarte()) {
                    cout << "Carte trouvee" << endl;
                    vuecartesbas[i]->setNoCarte();
                    if (controller->getJoueurActuel() == 1) {
                        for (int l = 0; l < 9; l++) {
                            for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_1().size(); j++) {
                                if (carte_selectionne == controller->getSchottenTotten().getBorne(l).getCartes_joueur_1()[j] && !controller->getSchottenTotten().getBorne(l).GetPossesseur()) {
                                    cout << "carte à supprimer du joueur 1" << endl;
                                    cout << "l : " << l << "j : " << j << endl;
                                    cout << "size vecteur : " << controller->getSchottenTotten().getBorne(l).getCartes_joueur_1().size();
                                    carte_selectionne = &controller->getSchottenTotten().getBorne(l).supprimer_carte(controller->getJoueurActuel(), j);
                                    controller->getDefausse().ajout_defausse(carte_selectionne);
                                }
                            }
                        }

                    }

                    if (controller->getJoueurActuel() == 2) {
                        for (int l = 0; l < 9; l++) {
                            for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_2().size(); j++) {
                                if (carte_selectionne == controller->getSchottenTotten().getBorne(l).getCartes_joueur_2()[j] && !controller->getSchottenTotten().getBorne(l).GetPossesseur()) {
                                    cout << "carte à supprimer du joueur 2" << endl;
                                    cout << "l : " << l << "j : " << j << endl;
                                    cout << "size vecteur : " << controller->getSchottenTotten().getBorne(l).getCartes_joueur_2().size();
                                    controller->getSchottenTotten().getBorne(l).supprimer_carte(controller->getJoueurActuel(), j);
                                }
                            }
                        }

                    }
                    cout << "ajout carte" << endl;
                    controller->getSchottenTotten().getBorne(vc->getNbBorne()).ajout_Carte(carte_selectionne, controller->getJoueurActuel());

                }
            }
            carte_stratege = false;
            updateVueCards();

            return;
        }
        cout << "carte non présente" << endl;

        if (carte_selectionne != nullptr && carte_exception) { //On a cliqué auparavant sur une carte traitre.
            if (controller->getJoueurActuel() == 1) {
                if (vuebornes[vc->getNbBorne()]->getBorne().getCartes_joueur_1().size() == vuebornes[vc->getNbBorne()]->getBorne().getNbMaxCartes()) {
                    cout << "nombre max de carte posé" << endl;
                    return;
                }
            }

            if (controller->getJoueurActuel() == 2) {
                if (vuebornes[vc->getNbBorne()]->getBorne().getCartes_joueur_2().size() == vuebornes[vc->getNbBorne()]->getBorne().getNbMaxCartes()) {
                    cout << "nombre max de carte posé" << endl;
                    return;
                }
            }

            for (int i = 0; i < vuecarteshaut.size(); i++) {
                if (carte_selectionne == &vuecarteshaut[i]->getCarte()) {
                    vuecarteshaut[i]->setNoCarte();
                    cout << "borne nb : " << vc->getNbBorne() << endl;

                    controller->getSchottenTotten().getBorne(vc->getNbBorne()).ajout_Carte(carte_selectionne, controller->getJoueurActuel());
                    if (controller->getJoueurActuel() == 1) {
                        vuecarteshaut[i]->setNoCarte();
                        for (int l = 0; l < controller->getSchottenTotten().getNb_bornes(); l++) {

                            for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_2().size(); j++) {
                                if (controller->getSchottenTotten().getBorne(l).getCartes_joueur_2()[j] == carte_selectionne) {
                                    controller->getSchottenTotten().getBorne(l).supprimer_carte(2, j);
                                    break;
                                }
                            }
                        }

                    }

                    if (controller->getJoueurActuel() == 2) {
                        vuecarteshaut[i]->setNoCarte();
                        for (int l = 0; l < controller->getSchottenTotten().getNb_bornes(); l++) {

                            for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_1().size(); j++) {
                                if (controller->getSchottenTotten().getBorne(l).getCartes_joueur_1()[j] == carte_selectionne) {
                                    controller->getSchottenTotten().getBorne(l).supprimer_carte(1, j);
                                    break;
                                }
                            }
                        }
                    }

                }
            }
            for (int i = 0; i < vuecartesbas.size(); i++) {
                if (carte_selectionne == &vuecartesbas[i]->getCarte()) {
                    return;
                }
            }
            vueCarteSelectionne->setNoCarte();
            carte_exception = false;
            carte_place = true;
            updateVueCards();
            return;
        }


        if (carte_selectionne != nullptr) {
            //bool dejaPlace = false;
            for (int i = 0; i < vuecarteshaut.size(); i++) {
                if (!carte_exception && carte_selectionne == &vuecarteshaut[i]->getCarte()) {
                    return;
                }
            }
            for (int i = 0; i < vuecartesbas.size(); i++) {
                if (carte_selectionne == &vuecartesbas[i]->getCarte()) {
                    return;
                }
            }
            if (vuebornes[vc->getNbBorne()]->getBorne().GetPossesseur()) {
                return;
            }

            if (controller->getJoueurActuel() == 1) {
                if (vuebornes[vc->getNbBorne()]->getBorne().getCartes_joueur_1().size() == vuebornes[vc->getNbBorne()]->getBorne().getNbMaxCartes()) {
                    cout << "nombre max de carte posé" << endl;
                    return;
                }
            }
            if (controller->getJoueurActuel() == 2) {
                if (vuebornes[vc->getNbBorne()]->getBorne().getCartes_joueur_2().size() == vuebornes[vc->getNbBorne()]->getBorne().getNbMaxCartes()) {
                    cout << "nombre max de carte posé" << endl;
                    return;
                }
            }
            if (carte_exception) {
                cout << "exception" << endl;
            }
            vc->setCarte(*carte_selectionne);

            for (int i = 0; i < vuecartesjoueur.size(); i++) {

                if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                    cout << "i : " << i << endl;
                    if (carte_selectionne->getType() != "Elite" && carte_selectionne->getType() != "Clan") {
                        //On ne peut poser que des cartes Clan ou Elite sur une case vide.
                        return;
                    }

                    //vuebornes[vc->getNbBorne()]->getBorne().ajout_Carte(carte_selectionne, controller->getJoueurActuel());
                    //controller->getSchottenTotten().getBorne(vc->getNbBorne()).ajout_Carte(carte_selectionne, controller->getJoueurActuel());

                    controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);

                    if (variante == "normal") {
                        //La pioche est automatique
                        //cout << "size pioche : " << controller->getPioche("pioche clan").sizePioche() << endl;
                        //controller->getJoueur(controller->getJoueurActuel()).ajout_carte(&controller->getPioche("pioche clan").piocher_carte());
                        //cout << "size pioche : " <<controller->getPioche("pioche clan").sizePioche() << endl;
                        //updateVueCards();
                        //changerJoueur();
                        //updateVueCards();
                        carte_place = true;
                    }
                    if (variante == "tactique") {
                        //Pioche pas automatique car le joueur peut choisir.
                        carte_place = true;
                    }
                    controller->getSchottenTotten().getBorne(vc->getNbBorne()).ajout_Carte(carte_selectionne, controller->getJoueurActuel());
                    cout << "vecteur joueurs bornes : " << controller->getSchottenTotten().getBorne(vc->getNbBorne()).getCartes_joueur_2().size() << " " << controller->getSchottenTotten().getBorne(vc->getNbBorne()).getCartes_joueur_1().size() << endl;
                }
            }

            updateVueCards();
            carte_selectionne = nullptr;

        }

    }

    if (vc->cartePresente()) {
        cout << "carte presente dans le slot" << endl;
        carte_selectionne = &vc->getCarte(); //On récupère la carte
        vueCarteSelectionne = vc;
        if (carte_banshee) {
            cout << "banshee" << endl;
            for (int i = 0; i < vuecarteshaut.size(); i++) {
                if (carte_selectionne == &vuecarteshaut[i]->getCarte()) {
                    for (int l = 0; l < 9; l++) {
                        for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_1().size(); j++) {
                            if (carte_selectionne == controller->getSchottenTotten().getBorne(l).getCartes_joueur_1()[j] && !controller->getSchottenTotten().getBorne(l).GetPossesseur()) {
                                cout << "carte à supprimer du joueur 1" << endl;
                                cout << "l : " << l << "j : " << j << endl;
                                cout << "size vecteur : " << controller->getSchottenTotten().getBorne(l).getCartes_joueur_1().size();
                                carte_selectionne = &controller->getSchottenTotten().getBorne(l).supprimer_carte(1, j);
                                controller->getDefausse().ajout_defausse(carte_selectionne);
                                carte_banshee = false;
                                vueCarteSelectionne->setNoCarte();
                                updateVueCards();
                                carte_place = true;
                                return;
                            }
                        }

                        for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_2().size(); j++) {
                            if (carte_selectionne == controller->getSchottenTotten().getBorne(l).getCartes_joueur_2()[j] && !controller->getSchottenTotten().getBorne(l).GetPossesseur()) {
                                cout << "carte à supprimer du joueur 2" << endl;
                                cout << "l : " << l << "j : " << j << endl;
                                cout << "size vecteur : " << controller->getSchottenTotten().getBorne(l).getCartes_joueur_2().size();
                                carte_selectionne = &controller->getSchottenTotten().getBorne(l).supprimer_carte(2, j);
                                cout << "carte supprimee. Ajout à la defausse" << endl;
                                controller->getDefausse().ajout_defausse(carte_selectionne);
                                carte_banshee = false;
                                updateVueCards();
                                carte_place = true;
                                return;
                            }
                        }
                    }
                }
            }
        }

        //On a sélectionné la carte traitre.
        if (carte_selectionne != nullptr && carte_selectionne->getId() == "Traitre") {
            cout << "carte traitre. La carte va disparaitre et il sera possible de prendre une carte de "
                    "l'adversaire et de la mettre sur une borne a nous." << endl;
            controller->getDefausse().ajout_defausse(carte_selectionne);

            // On supprime la carte traitre des mains du joueur
            for (int i = 0; i < vuecartesjoueur.size(); i++) {
                if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                    controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);
                    break;
                }
            }
            cout << "carte supprimmee" << endl;
            vueCarteSelectionne->setNoCarte();

            //Permet à l'utilisateur de pouvoir recliquer sur une carte. Et en plus sur une carte qui n'est pas à lui
            //grâce à carte_exception
            carte_selectionne = nullptr;
            carte_exception = true;

            cout << "fin carte" << endl;
            updateVueCards();
        }

        else if (carte_selectionne != nullptr && carte_selectionne->getId() == "Stratège") {
            cout << "carte stratege. La carte va disparaitre et il sera possible de prendre une carte de "
                    "l'adversaire et de la mettre sur une borne a nous." << endl;
            controller->getDefausse().ajout_defausse(carte_selectionne);
            cout << "ajout defausse" << endl;
            // On supprime la carte stratege des mains du joueur
            for (int i = 0; i < vuecartesjoueur.size(); i++) {
                if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                    controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);
                    break;
                }
            }
            cout << "carte supprimmee" << endl;
            vueCarteSelectionne->setNoCarte();
            updateVueCards();
            //Permet à l'utilisateur de pouvoir recliquer sur une carte. Et en plus sur une carte qui n'est pas à lui
            //grâce à carte_exception
            carte_selectionne = nullptr;
            carte_stratege = true;
        }

        else if (carte_selectionne != nullptr && carte_selectionne->getId() == "Banshee") {
            cout << "carte banshee." << endl;
            controller->getDefausse().ajout_defausse(carte_selectionne);
            for (int i = 0; i < vuecartesjoueur.size(); i++) {
                if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                    controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);
                    break;
                }
            }
            cout << "carte supprimmee" << endl;
            vueCarteSelectionne->setNoCarte();

            //Permet à l'utilisateur de pouvoir recliquer sur une carte. Et en plus sur une carte qui n'est pas à lui
            //grâce à carte_exception
            carte_selectionne = nullptr;
            carte_banshee = true;
            updateVueCards();

        }

        else if (carte_selectionne != nullptr && carte_selectionne->getId() == "Chasseur de Tête") {
            cout << "Carte chasseur de tête" << endl;
            controller->getDefausse().ajout_defausse(carte_selectionne);
            for (int i = 0; i < vuecartesjoueur.size(); i++) {
                if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                    controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);
                    break;
                }
            }

            vueCarteSelectionne->setNoCarte();
            carte_selectionne = nullptr;
            carte_chasseur_de_tete = true;
            compte_pioche = 0;
            updateVueCards();
        }

    }
    updateVueCards();
    update();
}

void VuePartie::onPiocheClicked(VuePioche *p) {

    if (carte_chasseur_de_tete) {
        //Peut piocher 3 cartes. Dans la pioche clan ou dans la pioche tactique.
        //Ajoute les cartes dans les mains du joueur.
        if (compte_pioche < 3) {
            if (p->getNomPioche() == "pioche clan") {
                if (controller->getPioche("pioche clan").est_vide()) {
                    cout << "pas possible de piocher, pioche vide" << endl;
                    return;
                }
                controller->getJoueur(controller->getJoueurActuel()).ajout_carte(&controller->getPioche("pioche clan").piocher_carte());
                compte_pioche++;
            }
            if (p->getNomPioche() == "pioche tactique") {
                if (controller->getPioche("pioche tactique").est_vide()) {
                    cout << "pas possible de piocher, pioche vide" << endl;
                    return;
                }
                controller->getJoueur(controller->getJoueurActuel()).ajout_carte(&controller->getPioche("pioche tactique").piocher_carte());
                compte_pioche++;
            }


        }

        if (compte_pioche == 3 && cartes_choisies < 2) {
            if (carte_selectionne != nullptr) {
                //ajoute la carte dans la pioche
                if (p->getNomPioche() == "pioche clan") {
                    controller->getPioche("pioche clan").ajoutcarte(carte_selectionne);
                    cout << "ajout pioche clan" << endl;
                    //Supprime la carte dans la main du joueur
                    for (int i = 0; i < vuecartesjoueur.size(); i++) {
                        if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                            controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);
                            break;
                        }
                    }

                    vueCarteSelectionne->setNoCarte();
                    carte_selectionne = nullptr;
                }

                if (p->getNomPioche() == "pioche tactique") {
                    controller->getPioche("pioche tactique").ajoutcarte(carte_selectionne);
                    cout << "ajout pioche tactique" << endl;
                    //Supprime la carte dans la main du joueur
                    for (int i = 0; i < vuecartesjoueur.size(); i++) {
                        if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {
                            controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i+1);
                            break;
                        }
                    }
                    vueCarteSelectionne->setNoCarte();
                    carte_selectionne = nullptr;
                }

                cartes_choisies++;
                if (cartes_choisies == 2) {
                    carte_place = true;
                }
            }
        }
    }

    if (carte_place && p->getNomPioche() == "pioche clan") {
        cout << "Pioche clan" << endl;
        if (controller->getPioche("pioche clan").est_vide()) {
            cout << "pas possible de piocher, pioche vide" << endl;
            return;
        }
        controller->getJoueur(controller->getJoueurActuel()).ajout_carte(&controller->getPioche("pioche clan").piocher_carte());

    }

    if (carte_place && p->getNomPioche() == "pioche tactique") {
        cout << "Pioche tactique" << endl;
        cout << "size pioche " << controller->getPioche("pioche tactique").sizePioche() << endl;
        if (controller->getPioche("pioche tactique").est_vide()) {
            cout << "pas possible de piocher, pioche vide" << endl;
            return;
        }
        controller->getJoueur(controller->getJoueurActuel()).ajout_carte(&controller->getPioche("pioche tactique").piocher_carte());

    }
    for (int i = 0; i < controller->getJoueur(controller->getJoueurActuel()).getNbCartes(); i++) {
        cout << "c : " << *controller->getJoueur(controller->getJoueurActuel()).getCartes()[i] << endl;
    }

    carte_place = false;
    updateVueCards();
    changerJoueur();
    updateVueCards();

}

void VuePartie::verif_bornes() {
    for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
        controller->revendication_borne(i);
    }
    updateVueCards();
}

void VuePartie::changerJoueur() {
    verif_bornes();
    for (int i = 0; i < vuecartesjoueur.size(); i++) {
        vuecartesjoueur[i]->setNoCarte();
    }
    if (controller->getJoueurActuel() == 1) {
        controller->setJoueurActuel(2);
        return;
    }

    controller->setJoueurActuel(1);
    for (int i = 0; i < controller->getSchottenTotten().getNb_bornes()-2; i++) {
        cout << "i : " << i << endl;
        cout << "borne : " << controller->getSchottenTotten().getBorne(i).GetPossesseur() << endl;
        if (controller->getSchottenTotten().getBorne(i).GetPossesseur() == 1 && controller->getSchottenTotten().getBorne(i).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  && controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+2).GetPossesseur() ) {
            //cout << schottenTotten->bornes[i]->GetPossesseur() << endl;
            //cout << "Joueur " << joueurs[0]->getNom() << " a gagne" << endl;
            controller->getJoueur(1).setNbPoints(5);
            //joueur_gagnant = schottenTotten->bornes[i]->GetPossesseur();
            string msg = "Le joueur 1 a gagné";
            showInfo(msg.c_str());
            return;
        }

        if (controller->getSchottenTotten().getBorne(i).GetPossesseur() == 1 && controller->getSchottenTotten().getBorne(i).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  && controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+2).GetPossesseur()) {
            controller->getJoueur(2).setNbPoints(5);
            //joueur_gagnant = schottenTotten->bornes[i]->GetPossesseur();
            string msg = "Le joueur 2 a gagné";
            showInfo(msg.c_str());
            return;
        }
    }

    if (controller->gagnant()) {
        //Donner le gagnant
        int bornes_j1 = 0;
        int bornes_j2 = 0;
        for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
            if (controller->getSchottenTotten().getBorne(i).GetPossesseur() == 1) {
                bornes_j1++;
            }

            else if (controller->getSchottenTotten().getBorne(i).GetPossesseur() == 2) {
                bornes_j2++;
            }
        }

        if (bornes_j1 == 5) {
            cout << "Joueur 1 gagne" << endl;
            controller->getJoueur(1).setNbPoints(5);
            string msg = "Le joueur 1 a gagné";
            showInfo(msg.c_str());
            //joueur_gagnant = 1;

        }

        if (bornes_j2 == 5) {
            cout << "Joueur 2 gagne" << endl;
            controller->getJoueur(2).setNbPoints(5);
            string msg = "Le joueur 2 a gagné";
            showInfo(msg.c_str());
            //joueur_gagnant = 2;

        }

        for (int i = 0; i < controller->getSchottenTotten().getNb_bornes()-2; i++) {

            if (controller->getSchottenTotten().getBorne(i).GetPossesseur() == 1 && controller->getSchottenTotten().getBorne(i).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  && controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+2).GetPossesseur() ) {
                //cout << schottenTotten->bornes[i]->GetPossesseur() << endl;
                //cout << "Joueur " << joueurs[0]->getNom() << " a gagne" << endl;
                controller->getJoueur(1).setNbPoints(5);
                //joueur_gagnant = schottenTotten->bornes[i]->GetPossesseur();
                string msg = "Le joueur 1 a gagné";
                showInfo(msg.c_str());
                return;
            }

            if (controller->getSchottenTotten().getBorne(i).GetPossesseur() == 1 && controller->getSchottenTotten().getBorne(i).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  && controller->getSchottenTotten().getBorne(i+1).GetPossesseur()  == controller->getSchottenTotten().getBorne(i+2).GetPossesseur()) {
                controller->getJoueur(2).setNbPoints(5);
                //joueur_gagnant = schottenTotten->bornes[i]->GetPossesseur();
                string msg = "Le joueur 2 a gagné";
                showInfo(msg.c_str());
                return;
            }
        }

        return;
    }

    if (controller->verif_partie()) {
        showInfo("fin de la partie");
    }

}


void VuePartie::clearvues() {
    for (int i = 0; i < vuecarteshaut.size(); i++) {
        vuecarteshaut[i]->setNoCarte();
    }

    for (int i = 0; i < vuecartesbas.size(); i++) {
        vuecartesbas[i]->setNoCarte();
    }

    for (int i = 0; i < vuecartesjoueur.size(); i++) {
        vuecartesjoueur[i]->setNoCarte();
    }

}

void VuePartie::updateVueCards() {


    clearvues();
    //verif_bornes();
    for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
        vuebornes[i]->setBorne(controller->getSchottenTotten().getBorne(i),i);
    }


    //Met les cartes du joueur adverse en haut
    if (controller->getJoueurActuel() == 1) {

        for (int i = 0; i < controller->getJoueur(1).getNbCartes(); i++) {
            //Prend les cartes du joueur actuel
            vuecartesjoueur[i]->setCarte(*controller->getJoueur(1).getCartes()[i]);
        }

        //Le joueur 2 est en haut.
        for (int i = 0; i < controller->getSchottenTotten().getNb_bornes(); i++) {
            for (int j = 0; j < controller->getSchottenTotten().getBorne(i).getCartes_joueur_2().size(); j++) {
                //cout << "size borne  " << i << " : " << controller->getSchottenTotten().getBorne(i).getCartes_joueur_2().size();
                //cout << "c : " << *controller->getSchottenTotten().getBorne(i).getCartes_joueur_2()[j] << endl;
                //cout << "i*4+j :" << i*4 + j << endl;
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
                //cout << "size borne " << i << " : " << controller->getSchottenTotten().getBorne(i).getCartes_joueur_1().size();
                //cout << "c : " << *controller->getSchottenTotten().getBorne(i).getCartes_joueur_1()[j] << endl;
                //cout << "i*4+j :" << i*4 + j << endl;
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

void VuePartie::onBorneClicked(VueBorne *b) {
    cout << "Borne cliquée" << endl;
    if (carte_selectionne != nullptr) {
        if (carte_selectionne->getType() == "Combat") {
            //Une carte mode de combat veut être posée sur une borne.
            controller->getSchottenTotten().getBorne(b->getNbBorne()).ajoutRegle(carte_selectionne->getRegle());

            for (int i = 0; i < vuecartesjoueur.size(); i++) {

                if (carte_selectionne == &vuecartesjoueur[i]->getCarte()) {

                    controller->getJoueur(controller->getJoueurActuel()).supprimerCarte(i + 1);
                    updateVueCards();
                    vueCarteSelectionne->setNoCarte();
                    carte_place = true;
                }
            }
        }
    }
}

void VuePartie::verifPartie() {
    if (controller->gagnant()) {
        string str = "Le joueur " + controller->getJoueur(controller->getJoueurGagnant()).getNom() + " a gagne.";
        showInfo(str.c_str());

    }
}

void VuePartie::showInfo(const char *message) {
    QMessageBox messageBox(QMessageBox::Icon::Warning, "Info : ", message);
    messageBox.exec();
}

void VuePartie::onDefausseClicked(VueDefausse *d) {
    cout << "defausse cliquée" << endl;
    if (carte_selectionne != nullptr) {
        controller->getDefausse().ajout_defausse(carte_selectionne);
    }
    if (carte_selectionne != nullptr && carte_stratege) {
        //Cas carte stratege selectionnee auparavant
        for (int i = 0; i < vuecartesbas.size(); i++) {
            if (carte_selectionne == &vuecartesbas[i]->getCarte()) {
                vuecartesbas[i]->setNoCarte();
                if (controller->getJoueurActuel() == 1) {
                    for (int l = 0; l < 9; l++) {
                        for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_1().size(); i++) {
                            if (carte_selectionne == controller->getSchottenTotten().getBorne(l).getCartes_joueur_1()[j]) {
                                controller->getSchottenTotten().getBorne(l).supprimer_carte(controller->getJoueurActuel(), j);
                            }
                        }
                    }

                }

                if (controller->getJoueurActuel() == 2) {
                    for (int l = 0; l < 9; l++) {
                        for (int j = 0; j < controller->getSchottenTotten().getBorne(l).getCartes_joueur_2().size(); i++) {
                            if (carte_selectionne == controller->getSchottenTotten().getBorne(l).getCartes_joueur_2()[j]) {
                                controller->getSchottenTotten().getBorne(l).supprimer_carte(controller->getJoueurActuel(), j);
                            }
                        }
                    }

                }
                //controller->getSchottenTotten().getBorne(vc->getNbBorne()).ajout_Carte(carte_selectionne, controller->getJoueurActuel());

            }
        }
        carte_stratege = false;

        return;
    }
    VueAjouterDefausse* vueajoutedefausse = new VueAjouterDefausse(controller->getDefausse(), this);
    vueajoutedefausse->show();
    updateVueCards();

}
