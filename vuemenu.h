#ifndef VUEMENU_H
#define VUEMENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class VueMenu : public QWidget
{
    Q_OBJECT

public:
    explicit VueMenu(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        QLabel *label = new QLabel(this);
        label->setText(
            "    _____      _             _   _               _______     _   _             \n"
            "   / ____|    | |           | | | |             |__   __|   | | | |            \n"
            "  | (___   ___| |__    ___  | |_| |_ ___ _ __      | | ___  | |_| |_ ___ _ __  \n"
            "  \\___ \\/ __| '_ \\ / _ \\| __| __/ _ \\ '_ \\   | |/ _ \\| __| __/ _ \\ '_\\ \n"
            "  ____) | (__ | | | || (_) ||_| ||    __/ | | |    | | (_)  | |_| ||  __/ | | |\n"
            " |_____/ \\___|_| |_| \___/ \\__|\\__\\___|_| |_|  |_|\___/ \\__|\\__\\___|_| |_|\n"
            "                                                                           \n"
            "                                                                           "
            );
        label->adjustSize();

        boutonVarianteNormale = new QPushButton("Variante Normale", this);
        boutonVarianteTactique = new QPushButton("Variante Tactique", this);
        boutonUnJoueur = new QPushButton("1 Joueur", this);
        boutonDeuxJoueurs = new QPushButton("2 Joueurs", this);


        connect(boutonVarianteNormale, &QPushButton::clicked, this, &VueMenu::onVarianteNormaleClicked);
        connect(boutonVarianteTactique, &QPushButton::clicked, this, &VueMenu::onVarianteTactiqueClicked);
        connect(boutonUnJoueur, &QPushButton::clicked, this, &VueMenu::onUnJoueurClicked);
        connect(boutonDeuxJoueurs, &QPushButton::clicked, this, &VueMenu::onDeuxJoueursClicked);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(boutonVarianteNormale);
        layout->addWidget(boutonVarianteTactique);
        layout->addWidget(boutonUnJoueur);
        layout->addWidget(boutonDeuxJoueurs);


        setLayout(layout);
        resize(1000,1000);
    }

    void setVarianteNormaleSelected(bool selected)
    {
        boutonVarianteNormale->setChecked(selected);
    }

    void setVarianteTactiqueSelected(bool selected)
    {
        boutonVarianteTactique->setChecked(selected);
    }

    void setUnJoueurSelected(bool selected)
    {
        boutonUnJoueur->setChecked(selected);
    }

    void setDeuxJoueursSelected(bool selected)
    {
        boutonDeuxJoueurs->setChecked(selected);
    }

signals:
    void varianteNormaleSelected();
    void varianteTactiqueSelected();
    void unJoueurSelected();
    void deuxJoueursSelected();

private slots:
    void onVarianteNormaleClicked()
    {
        emit varianteNormaleSelected();
    }

    void onVarianteTactiqueClicked()
    {
        emit varianteTactiqueSelected();

    }

    void onUnJoueurClicked()
    {
        emit unJoueurSelected();

    }

    void onDeuxJoueursClicked()
    {
        emit deuxJoueursSelected();
    }

private:
    QPushButton *boutonVarianteNormale;
    QPushButton *boutonVarianteTactique;
    QPushButton *boutonUnJoueur;
    QPushButton *boutonDeuxJoueurs;
};

#endif // VUEMENU_H
