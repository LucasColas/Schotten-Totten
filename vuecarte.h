//
// Created by lucas on 20/05/2023.
//

#ifndef SCHOTTEN_TOTTEN_VUECARTE_H
#define SCHOTTEN_TOTTEN_VUECARTE_H
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "Carte.h"
class VueCarte : public QPushButton {
Q_OBJECT
private:
    Carte* carte= nullptr;
    int nb_borne;
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    VueCarte(Carte& c, QWidget *parent = nullptr);
    explicit VueCarte(QWidget *parent = nullptr);
    ~VueCarte();
    // affecter une nouvelle carte à la vue
    void setCarte(Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    // vue sans carte
    void setNoCarte() { carte=nullptr; setCheckable(false); update(); }
    Carte& getCarte() const { return *carte; }
    bool cartePresente() const { return carte!=nullptr; }

    void setNbBorne(int i);
    int getNbBorne() const {return nb_borne;};

signals:
    // quand la vue de de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueCarte*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};
#endif //SCHOTTEN_TOTTEN_VUECARTE_H
