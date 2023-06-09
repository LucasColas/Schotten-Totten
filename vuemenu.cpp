#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "vuemenu.h"

VueMenu::VueMenu()
{
    setWindowTitle("Menu Schotten Totten");
    txtchoix = new QLabel("Choisissez votre jeu, sa variante et le nombre de joueurs", this);
    boutonST = new QPushButton("Schotten Totten", this);
    boutonST2 = new QPushButton("Schotten Totten 2", this);
    boutonVarianteNormale = new QPushButton("Variante Normale", this);
    boutonVarianteTactique = new QPushButton("Variante Tactique", this);
    boutonUnJoueur = new QPushButton("1 Joueur", this);
    boutonDeuxJoueurs = new QPushButton("2 Joueurs", this);
    boutonLancerPartie = new QPushButton("Lancer la partie", this);
    boutonQuitter = new QPushButton("Quitter", this);

    connect(boutonST,SIGNAL(clicked()), this, SLOT(onSTClicked()));
    connect(boutonST2,SIGNAL(clicked()), this, SLOT(onST2Clicked()));
    connect(boutonVarianteNormale, SIGNAL(clicked()), this, SLOT(onVarianteNormaleClicked()));
    connect(boutonVarianteTactique, SIGNAL(clicked()), this, SLOT(onVarianteTactiqueClicked()));
    connect(boutonUnJoueur, SIGNAL(clicked()), this, SLOT(onUnJoueurClicked()));
    connect(boutonDeuxJoueurs, SIGNAL(clicked()), this, SLOT(onDeuxJoueursClicked()));
    connect(boutonLancerPartie, SIGNAL(clicked()), this,SLOT(onLancerPartieClicked()));
    connect(boutonQuitter, SIGNAL(clicked()), this, SLOT(onQuitterClicked()));

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(txtchoix);
    layout->addWidget(boutonST);
    layout->addWidget(boutonST2);
    layout->addWidget(boutonVarianteNormale);
    layout->addWidget(boutonVarianteTactique);
    layout->addWidget(boutonUnJoueur);
    layout->addWidget(boutonDeuxJoueurs);
    layout->addWidget(boutonLancerPartie);
    layout->addWidget(boutonQuitter);


    setLayout(layout);
    resize(200,200);
}


void VueMenu::onVarianteNormaleClicked()
{
    boutonVarianteNormale->setCheckable(true);
    boutonVarianteTactique->setCheckable(false);

}

void VueMenu::onVarianteTactiqueClicked()
{
    boutonVarianteNormale->setCheckable(false);
    boutonVarianteTactique->setCheckable(true);
}

void VueMenu::onUnJoueurClicked()
{
    boutonUnJoueur->setCheckable(true);
    boutonDeuxJoueurs->setCheckable(false);
}

void VueMenu::onDeuxJoueursClicked()
{
    boutonUnJoueur->setCheckable(false);
    boutonDeuxJoueurs->setCheckable(true);
}
void VueMenu::onSTClicked()
{
    boutonST->setCheckable(true);
    boutonST2->setCheckable(false);
}
void VueMenu::onST2Clicked()
{
    boutonST->setCheckable(false);
    message= new QMessageBox();
    message->setText("Désolé, cette version n'est pas implémentée");
    message->show();
}

void VueMenu::onLancerPartieClicked(){
    std::vector<std::string> noms;
    message= new QMessageBox();



    if (boutonST->isChecked() && boutonVarianteNormale->isChecked() && boutonUnJoueur->isChecked() ){
        noms.push_back("J1");
        noms.push_back("IA");

        message->setText("Partie lancée");
        message->show();
        QMainWindow* mainWindow= new QMainWindow();
        partie = new VuePartie("Schotten Totten", "normal", 1, 1, noms);
        mainWindow->setCentralWidget(partie);
        mainWindow->show();


    }
    else if (boutonST->isChecked() && boutonVarianteNormale->isChecked() && boutonDeuxJoueurs->isChecked() ){

        noms.push_back("J1");
        noms.push_back("J2");

        QMainWindow* mainWindow= new QMainWindow();
        partie = new VuePartie("Schotten Totten", "normal", 1, 2, noms);
        mainWindow->setCentralWidget(partie);
        mainWindow->show();
    }
    else if (boutonST->isChecked() && boutonVarianteTactique->isChecked() && boutonUnJoueur->isChecked() ){

        noms.push_back("J1");
        noms.push_back("IA");

        QMainWindow* mainWindow= new QMainWindow();
        partie = new VuePartie("Schotten Totten", "tactique", 1, 1, noms);
        mainWindow->setCentralWidget(partie);
        mainWindow->show();
    }
    else if (boutonST->isChecked() && boutonVarianteTactique->isChecked() && boutonDeuxJoueurs->isChecked() ){

        noms.push_back("J1");
        noms.push_back("J2");

        QMainWindow* mainWindow= new QMainWindow();
        partie = new VuePartie("Schotten Totten", "tactique", 1, 2, noms);
        mainWindow->setCentralWidget(partie);
        mainWindow->show();
    }

    else{
        message->setText("Erreur lors de la sélection");
        message->show();
    }
}

void VueMenu::onQuitterClicked(){
    QCoreApplication::quit();
}
