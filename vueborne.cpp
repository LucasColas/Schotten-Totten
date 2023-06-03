//
// Created by lucas on 20/05/2023.
//
#include "vueborne.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
VueBorne::VueBorne(Borne &c, QWidget *parent) {
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(50,70);
    //connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

VueBorne::VueBorne(QWidget *parent) {
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(50,70);
    //connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void VueBorne::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (borne==nullptr) {
        painter.drawText(QRect(5,10,width(),10), Qt::AlignCenter, tr("vide"));
        return;
    }
    painter.drawText(QRect(5, 10, width(), 10), Qt::AlignCenter, tr((borne->getId() + " P : " + std::to_string(borne->GetPossesseur())).c_str()));

}