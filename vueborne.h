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
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    VueBorne(Borne& c, QWidget *parent = nullptr);
    //virtual ~VueBorne();
    explicit VueBorne(QWidget *parent = nullptr);
    // affecter une nouvelle borne à la vue
    void setBorne(Borne& c) { setCheckable(true); setChecked(false); borne=&c; update(); }
    // vue sans carte
    void setNoCarte() { borne=nullptr; setCheckable(false); update(); }
    Borne& getBorne() const { return *borne; }
    bool BornePresente() const { return borne!=nullptr; }
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void BorneClicked(VueBorne*);
public slots:
private slots:
    void clickedEvent() { emit BorneClicked(this); }
};
#endif //SCHOTTEN_TOTTEN_VUEBORNE_H
