#include "vuedefausse.h"

#include <QPainter>
#include <QString>
#include <QStaticText>

VueDefausse::VueDefausse(const Defausse& d, QWidget* parent){
    setWindowTitle("Défausse");
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(700,300);

    for (size_t i = 0; i < d.Defausse::getNbCartes(); i++) {
        vueCartesDefausse[i] = new VueCarte;
    }

    layoutCartesDefausse = new QGridLayout;

    for(size_t i = 0; i < d.Defausse::getNbCartes(); i++){
        layoutCartesDefausse->addWidget(vueCartesDefausse[i],1,i);
    }
}
