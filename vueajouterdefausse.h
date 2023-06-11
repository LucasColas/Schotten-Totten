//
// Created by lucas on 08/06/2023.
//

#ifndef SCHOTTEN_TOTTEN_VUEAJOUTERDEFAUSSE_H
#define SCHOTTEN_TOTTEN_VUEAJOUTERDEFAUSSE_H
#include "defausse.h"
#include "vuecarte.h"
#include "Jeu.h"

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include "defausse.h"
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include "defausse.h"
#include "vuecarte.h"

class VueAjouterDefausse : public QMainWindow {
Q_OBJECT
private:
    Defausse* defausse = nullptr;
    vector<VueCarte*> vuescartes;
    QGridLayout* firstCardsGridLayout;

public:
    VueAjouterDefausse(Defausse& d,QWidget *parent = nullptr);
    void updateVueAjouterDefausse();
};

#endif //SCHOTTEN_TOTTEN_VUEAJOUTERDEFAUSSE_H
