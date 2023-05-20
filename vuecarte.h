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
private:
    const Carte* carte= nullptr;
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    VueCarte(const Carte& c, QWidget *parent = nullptr);
    explicit VueCarte(QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    void setCarte(const Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    // vue sans carte
    void setNoCarte() { carte=nullptr; setCheckable(false); update(); }
    const Carte& getCarte() const { return *carte; }
    bool cartePresente() const { return carte!=nullptr; }
};
#endif //SCHOTTEN_TOTTEN_VUECARTE_H
