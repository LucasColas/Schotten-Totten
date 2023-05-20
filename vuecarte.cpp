//
// Created by lucas on 20/05/2023.
//
#include "vuecarte.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
VueCarte::VueCarte(const Carte& c, QWidget *parent) : QPushButton(parent),carte(&c)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120,200);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120,200);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void VueCarte::paintEvent(QPaintEvent * /* event */) {
    QPainter painter(this);
    if (carte==nullptr) { // si la vue de carte n'a pas de carte on affiche un message
        painter.drawText(QRect(15,50,100,60), Qt::AlignCenter, tr("cliquer \n pour \n ajouter \n une carte"));
        return;
    }
}