//
// Created by lucas on 01/06/2023.
//

#include "vuepioche.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include "string"
VuePioche::~VuePioche()= default;

VuePioche::VuePioche(Pioche &c, string nomp_, QWidget *parent) {
    setBackgroundRole(QPalette::Base);
    nompioche = nomp_;
    setAutoFillBackground(true);
    setFixedSize(100,30);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}


VuePioche::VuePioche(string nomp_, QWidget *parent) {
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(100,30);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
    nompioche = nomp_;
}

void VuePioche::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    /*if (pioche==nullptr) { // si la vue de carte n'a pas de carte on affiche un message
        painter.drawText(QRect(0,10,width(),10), Qt::AlignCenter, tr("vide"));
        return;
    }*/
    const char* s = nompioche.c_str();
    painter.drawText(QRect(0, 10, width(), 15), Qt::AlignCenter, tr(s));

}
