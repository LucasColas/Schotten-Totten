#ifndef SCHOTTEN_TOTTEN_VUEDEFAUSSE_H
#define SCHOTTEN_TOTTEN_VUEDEFAUSSE_H

#include "defausse.h"
#include "vuecarte.h"

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>


class VueDefausse : public QWidget {
Q_OBJECT
private :
    const Defausse* defausse = nullptr;
    QGridLayout* layoutCartesDefausse;
    vector<VueCarte*> vueCartesDefausse;
public :
    VueDefausse(const Defausse& d, QWidget* parent = nullptr);
};

class QPushButtonDefausse : public QPushButton {
Q_OBJECT
private :
    VueDefausse* vuedefausse;
};


#endif SCHOTTEN_TOTTEN_VUEDEFAUSSE_H