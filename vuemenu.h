#ifndef VUEMENU_H
#define VUEMENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "vuepartie.h"

class VueMenu : public QWidget
{
    Q_OBJECT
private:
    QLabel *txtchoix;
    QPushButton *boutonST;
    QPushButton *boutonVarianteNormale;
    QPushButton *boutonVarianteTactique;
    QPushButton *boutonUnJoueur;
    QPushButton *boutonDeuxJoueurs;
    QPushButton *boutonLancerPartie;
    QMessageBox *message;
    VuePartie *partie;


public:

    VueMenu(QWidget *parent = nullptr) : QWidget(parent)
    {
        setWindowTitle("Menu Schotten Totten");
        txtchoix = new QLabel("Choisissez votre jeu, sa variante et le nombre de joueurs", this);
        boutonST = new QPushButton("Schotten Totten", this);
        boutonVarianteNormale = new QPushButton("Variante Normale", this);
        boutonVarianteTactique = new QPushButton("Variante Tactique", this);
        boutonUnJoueur = new QPushButton("1 Joueur", this);
        boutonDeuxJoueurs = new QPushButton("2 Joueurs", this);
        boutonLancerPartie = new QPushButton("Lancer la partie", this);

        connect(boutonST, &QPushButton::clicked, this, &VueMenu::onSTClicked);
        connect(boutonVarianteNormale, SIGNAL(clicked()), this, SLOT(onVarianteNormaleClicked()));

        connect(boutonVarianteTactique, SIGNAL(clicked()), this, SLOT(onVarianteTactiqueClicked()));
        connect(boutonUnJoueur, SIGNAL(clicked()), this, SLOT(onUnJoueurClicked()));
        connect(boutonDeuxJoueurs, SIGNAL(clicked()), this, SLOT(onDeuxJoueursClicked()));
        connect(boutonLancerPartie, &QPushButton::clicked, this, &VueMenu::onLancerPartieClicked);

        QVBoxLayout *layout = new QVBoxLayout(this);

        layout->addWidget(txtchoix);
        layout->addWidget(boutonST);
        layout->addWidget(boutonVarianteNormale);
        layout->addWidget(boutonVarianteTactique);
        layout->addWidget(boutonUnJoueur);
        layout->addWidget(boutonDeuxJoueurs);
        layout->addWidget(boutonLancerPartie);


        setLayout(layout);
        resize(100,100);
    }



signals:
    void varianteNormaleSelected(bool normalselected);
    void varianteTactiqueSelected(bool tactiqueselected);
    void unJoueurSelected(bool unJselected);
    void deuxJoueursSelected(bool deuxJselected);
    void STSelected(bool STselected);

private slots:
    void onVarianteNormaleClicked()
    {
        boutonVarianteNormale->setChecked(true);
        boutonVarianteTactique->setChecked(false);
        message= new QMessageBox();
        message->setText("Partie lancée");
        message->show();


    }

    void onVarianteTactiqueClicked()
    {
        boutonVarianteNormale->setChecked(false);
        boutonVarianteTactique->setChecked(true);
    }

    void onUnJoueurClicked()
    {
        boutonUnJoueur->setChecked(true);
        boutonDeuxJoueurs->setChecked(false);
    }

    void onDeuxJoueursClicked()
    {
        boutonUnJoueur->setChecked(false);
        boutonDeuxJoueurs->setChecked(true);
    }
    void onSTClicked()
    {
        boutonST->setChecked(true);
    }
    void onLancerPartieClicked(){


        if (boutonVarianteNormale->isChecked() && boutonUnJoueur->isChecked() ){
            cout<<"Normal et 1J";
            std::vector<std::string> noms;
            noms.push_back("J1");
            noms.push_back("IA");

            partie= new VuePartie("Schotten Totten", "normal", 1, 1, noms);
            message= new QMessageBox();
            message->setText("Partie lancée");
            message->show();
            partie->show();

        }
        else if (boutonVarianteNormale->isChecked() && boutonDeuxJoueurs->isChecked() ){
            cout<<"Normal et 2J";
            std::vector<std::string> noms;
            noms.push_back("J1");
            noms.push_back("J2");
            message= new QMessageBox();
            message->setText("Partie lancée");
            message->show();
            partie = new VuePartie("Schotten Totten", "normal", 1, 2, noms);
            partie->show();


        }
        else{
        message= new QMessageBox();
        message->setText("Erreur lors de la sélection");
        message->show();
        }
    }
};

#endif // VUEMENU_H
