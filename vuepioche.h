//
// Created by lucas on 01/06/2023.
//

#ifndef SCHOTTEN_TOTTEN_VUEPIOCHE_H
#define SCHOTTEN_TOTTEN_VUEPIOCHE_H
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "Pioche.h"

class VuePioche : public QPushButton {
Q_OBJECT
private:
    Pioche* pioche= nullptr;
    string nompioche;

protected:
    void paintEvent(QPaintEvent *event) override;
public:
    VuePioche(Pioche& c, string nomp_, QWidget *parent = nullptr);
    explicit VuePioche(string nomp_, QWidget *parent = nullptr);
    ~VuePioche();
    /*
    // affecter une nouvelle pioche à la vue
    void setPioche(Pioche& c) { setCheckable(true); setChecked(false); pioche=&c; update(); }
    // vue sans carte
    void setNoPioche() { pioche=nullptr; setCheckable(false); update(); }
    Pioche& getCarte() const { return *pioche; }
    bool cartePresente() const { return pioche!=nullptr; }
     */
    string& getNomPioche() {return nompioche;};


signals:
    // quand la vu de de pioche est cliquée, elle émet un signal en transmettant son adresse
    void PiocheClicked(VuePioche*);
public slots:
private slots:
    void clickedEvent() { emit PiocheClicked(this); }
};
#endif //SCHOTTEN_TOTTEN_VUEPIOCHE_H
