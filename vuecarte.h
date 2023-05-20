//
// Created by lucas on 20/05/2023.
//
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "Carte.h"
#ifndef SCHOTTEN_TOTTEN_VUECARTE_H
#define SCHOTTEN_TOTTEN_VUECARTE_H

class VueCarte : public QPushButton
{
Q_OBJECT
public:
    VueCarte(const Carte& c, QWidget *parent = nullptr);
    explicit VueCarte(QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    void setCarte(const Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    // vue sans carte
    void setNoCarte() { carte=nullptr; setCheckable(false); update(); }
    const Carte& getCarte() const { return *carte; }
    bool cartePresente() const { return carte!=nullptr; }
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    const Carte* carte=nullptr;
    QPen pen;
    QBrush brush;
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueCarte*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};
#endif //SCHOTTEN_TOTTEN_VUECARTE_H
