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
    const Borne* borne= nullptr;
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    VueBorne(const Borne& c, QWidget *parent = nullptr);
    //virtual ~VueBorne();
    explicit VueBorne(QWidget *parent = nullptr);
    // affecter une nouvelle borne à la vue
    void setBorne(const Borne& c) { setCheckable(true); setChecked(false); borne=&c; update(); }
    // vue sans carte
    void setNoCarte() { borne=nullptr; setCheckable(false); update(); }
    const Borne& getBorne() const { return *borne; }
    bool BornePresente() const { return borne!=nullptr; }
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueBorne*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};
#endif //SCHOTTEN_TOTTEN_VUEBORNE_H
