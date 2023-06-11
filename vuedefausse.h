//
// Created by lucas on 11/06/2023.
//

#ifndef SCHOTTEN_TOTTEN_VUEDEFAUSSE_H
#define SCHOTTEN_TOTTEN_VUEDEFAUSSE_H
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

class VueDefausse : public QPushButton {
Q_OBJECT
private:
    Defausse* defausse = nullptr;

protected:
    void paintEvent(QPaintEvent *event) override;
public:
    VueDefausse(Defausse& d, QWidget *parent = nullptr);
    explicit VueDefausse(QWidget *parent = nullptr);
    ~VueDefausse();
    void setDefausse(Defausse& d) {setCheckable(true); setChecked(false); defausse=&d; update();};


signals:
    // quand la vue de de carte est cliquée, elle émet un signal en transmettant son adresse
    void defausseClicked(VueDefausse*);
public slots:
private slots:
    void clickedEvent() { emit defausseClicked(this); }
};
#endif //SCHOTTEN_TOTTEN_VUEDEFAUSSE_H
