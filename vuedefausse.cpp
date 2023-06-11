//
// Created by lucas on 11/06/2023.
//
#include "vuedefausse.h"
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QPainter>
#include <QString>
#include <QStaticText>

VueDefausse::~VueDefausse()= default;
VueDefausse::VueDefausse(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(50,70);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

VueDefausse::VueDefausse(Defausse &d, QWidget *parent) : QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(50,70);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void VueDefausse::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawText(QRect(0,10,width(),10), Qt::AlignCenter, tr("Defausse"));
}