#ifndef VUEMENU_H
#define VUEMENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QMainWindow>
#include "vuepartie.h"

class VueMenu : public QWidget
{
    Q_OBJECT
private:
    QLabel *txtchoix;
    QPushButton *boutonST;
    QPushButton *boutonST2;
    QPushButton *boutonVarianteNormale;
    QPushButton *boutonVarianteTactique;
    QPushButton *boutonUnJoueur;
    QPushButton *boutonDeuxJoueurs;
    QPushButton *boutonLancerPartie;
    QPushButton *boutonQuitter;
    QMessageBox *message;
    VuePartie *partie;


public:

    explicit VueMenu();

signals:
    void varianteNormaleSelected(bool normalselected);
    void varianteTactiqueSelected(bool tactiqueselected);
    void unJoueurSelected(bool unJselected);
    void deuxJoueursSelected(bool deuxJselected);
    void STSelected(bool STselected);
    void ST2Selected(bool ST2selected);
    void QuitterSelected(bool QuitterSelected);

private slots:
    void onVarianteNormaleClicked();
    void onVarianteTactiqueClicked();
    void onUnJoueurClicked();
    void onDeuxJoueursClicked();
    void onSTClicked();
    void onST2Clicked();
    void onLancerPartieClicked();
    void onQuitterClicked();

};

#endif // VUEMENU_H
