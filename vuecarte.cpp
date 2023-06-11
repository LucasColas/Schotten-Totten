//
// Created by lucas on 20/05/2023.
//
#include "vuecarte.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include "string"

VueCarte::~VueCarte()= default;

VueCarte::VueCarte(Carte& c, QWidget *parent) : QPushButton(parent),carte(&c)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(40,60);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

void VueCarte::setNbBorne(int i) {
    nb_borne = i;
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(40,60);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void VueCarte::paintEvent(QPaintEvent * /* event */) {
    QPainter painter(this);
    if (carte==nullptr) { // si la vue de carte n'a pas de carte on affiche un message
        setStyleSheet("color: black;");
        painter.drawText(QRect(0,10,width(),10), Qt::AlignCenter, tr("vide"));
        return;
    }
    if (carte->getType() == "Clan") {
        string str = toString(carte->get_couleur()) + to_string(carte->get_force());
        const char* s = str.c_str();

        string couleur = toString(carte->get_couleur());
        if (couleur == "Bl")
            setStyleSheet("color: blue;");
        if (couleur == "Ro")
            setStyleSheet("color: red;");
        if (couleur == "Ve")
            setStyleSheet("color: green;");
        if (couleur == "Do")
            setStyleSheet("color: gold;");
        if (couleur == "Vi")
            setStyleSheet("color: purple;");
        if (couleur == "Ma")
            setStyleSheet("color: brown;");

        painter.drawText(QRect(0, 10, width(), 10), Qt::AlignCenter, tr(s));


        return;
    }

    string str = carte->getId();
    const char* s = str.c_str();
    painter.drawText(QRect(0, 10, width(), 10), Qt::AlignCenter, tr(s));


}