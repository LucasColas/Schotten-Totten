//
// Created by lucas on 08/06/2023.
//
#include "vueajouterdefausse.h"
#include "vuecarte.h"
VueAjouterDefausse::VueAjouterDefausse(Defausse& d,QWidget *parent) : QMainWindow(parent), vuescartes(10, nullptr) {

    defausse = &d;
    int index = 0;
    firstCardsGridLayout = new QGridLayout;;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            vuescartes[index] = new VueCarte;
            firstCardsGridLayout->addWidget(vuescartes[index], j, i);
            index++;
        }
    }
    updateVueAjouterDefausse();
    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(firstCardsGridLayout);
    setCentralWidget(centralWidget);

}

void VueAjouterDefausse::updateVueAjouterDefausse() {
    for (int i = 0; i < defausse->getNbCartes(); i++) {
        vuescartes[i]->setNoCarte();
    }
    for (int i = 0; i < defausse->getNbCartes(); i++) {
        vuescartes[i]->setCarte(defausse->getCarte(i));
    }
}