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

#include "vuecarte.h"
#include "vuepartie.h"
#include "vueborne.h"
VuePartie::~VuePartie() = default; // Add virtual destructor definition

VuePartie::VuePartie(QWidget *parent) : QWidget(parent), vuecartes(20, nullptr)
{
    setWindowTitle("Set !");


    deckLabel = new QLabel("Pioche");
    scoreLabel = new QLabel("Score");

    numberCardsDeckProgressBar = new QProgressBar;
    //numberCardsDeckProgressBar->setRange(0, Set::Jeu::getInstance().getNbCartes());
    //numberCardsDeckProgressBar->setValue(controller.getPioche().getNbCartes());
    numberCardsDeckProgressBar->setFixedHeight(30);

    scoreDisplayer = new QLCDNumber;
    scoreDisplayer->display(0);
    scoreDisplayer->setFixedHeight(30);

    informationsHeaderLayout = new QHBoxLayout;
    cardsGridLayout = new QGridLayout;
    layer = new QVBoxLayout;

    informationsHeaderLayout->addWidget(deckLabel);
    informationsHeaderLayout->addWidget(numberCardsDeckProgressBar);
    informationsHeaderLayout->addWidget(scoreLabel);
    informationsHeaderLayout->addWidget(scoreDisplayer);
    int index = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 4; ++j) {


        }
    }
    for (size_t i = 0; i < 20; i++) {
        vuecartes[i] = new VueCarte;
        cardsGridLayout->addWidget(vuecartes[i], i/4, i%4);

        connect(vuecartes[i], SIGNAL(carteClicked(VueCarte*)), this, SLOT(onCardClicked(VueCarte*)));
    }

    //updateVueCards();

    layer->addLayout(informationsHeaderLayout);
    layer->addLayout(cardsGridLayout);
    setLayout(layer);
}


void VuePartie::onCardClicked(VueCarte *vc)
{
    if (!vc->cartePresente()) {
        cout << "carte présente" << endl;
    }
    update();
}