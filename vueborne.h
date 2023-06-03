//
// Created by lucas on 20/05/2023.
//

#ifndef SCHOTTEN_TOTTEN_VUEBORNE_H
#define SCHOTTEN_TOTTEN_VUEBORNE_H
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "Borne.h"
class VueBorne : public QPushButton {
Q_OBJECT
private:
    Borne* borne= nullptr;
    int nb_borne;
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    VueBorne(Borne& c, int nb_b, QWidget *parent = nullptr);
    //virtual ~VueBorne();
    explicit VueBorne(int nb_b, QWidget *parent = nullptr);
    // affecter une nouvelle borne à la vue
    void setBorne(Borne& c, int nb_b) { setCheckable(true); setChecked(false); borne=&c; nb_borne = nb_b; update(); }
    // vue sans carte
    void setNoBorne() { borne=nullptr; setCheckable(false); update(); }
    Borne& getBorne() const { return *borne; }
    bool BornePresente() const { return borne!=nullptr; }
    int getNbBorne() const {return nb_borne;}
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void BorneClicked(VueBorne*);
public slots:
private slots:
    void clickedEvent() { emit BorneClicked(this); }
};
#endif //SCHOTTEN_TOTTEN_VUEBORNE_H
