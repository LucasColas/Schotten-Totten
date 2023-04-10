//
// Created by lucas on 09/04/2023.
//

#ifndef SCHOTTEN_TOTTEN_SET_H
#define SCHOTTEN_TOTTEN_SET_H
#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
using namespace std;

namespace Set {
    // classe pour gérer les exceptions dans le set
    class SetException {
    public:
        SetException(const string& i) :info(i) {}
        string getInfo() const { return info; }
    private:
        string info;
    };

    // caractéristiques
    enum class Couleur { rouge, mauve, vert };
    enum class Nombre { un=1, deux=2, trois=3 };
    enum class Forme { ovale, vague, losange };
    enum class Remplissage { plein, vide, hachure };

    // conversion d'une caractéristique en string
    string toString(Couleur c);
    string toString(Nombre v);
    string toString(Forme f);
    string toString(Remplissage v);

    // écriture d'une caractéristique sur un flux ostream
    ostream& operator<<(ostream& f, Couleur c);
    ostream& operator<<(ostream& f, Nombre v);
    ostream& operator<<(ostream& f, Forme x);
    ostream& operator<<(ostream& f, Remplissage r);

    // listes contenant les valeurs possibles pour chacune des caractéristiques
    extern std::initializer_list<Couleur> Couleurs;
    extern std::initializer_list<Nombre> Nombres;
    extern std::initializer_list<Forme> Formes;
    extern std::initializer_list<Remplissage> Remplissages;

    // affichage des valeurs possibles pour chaque caractéristiques
    void printCouleurs(std::ostream& f = cout);
    void printNombres(std::ostream& f = cout);
    void printFormes(std::ostream& f = cout);
    void printRemplissages(std::ostream& f = cout);

    /* Début de l'exercice 22 */

    class Carte {
    private:
        // Un attribut par caractéristique
        // On utilise les types enum
        Couleur couleur;
        Nombre nombre;
        Forme forme;
        Remplissage remplissage;

    public:
        // Accesseurs en lecture
        Couleur getCouleur() const { return couleur; }
        Nombre getNombre() const { return nombre; }
        Forme getForme() const { return forme; }
        Remplissage getRemplissage() const { return remplissage; }

        // Constructeur à 4 paramètres
        Carte(Couleur c, Nombre n, Forme f, Remplissage r) : couleur(c), nombre(n), forme(f), remplissage(r) {};

        // Destructeur
        ~Carte() = default; // optionnel
        // Constructeur par recopie
        Carte(const Carte& c) = default; // optionnel
        // Opérateur d'affectation
        Carte& operator=(const Carte& c) = default; // optionnel
    };

    class Jeu {
    private:
        // Tableau de pointeurs sur les cartes du jeu
        // Les cartes doivent être créées dynamiquement par l'objet Jeu
        const Carte* cartes[81];
    public:
        // Constructeur sans argument : crée les cartes
        Jeu();
        // Destructeur : libère les cartes
        ~Jeu();

        // Accesseurs en lecture
        size_t getNbCartes() const { return 81; }

        const Carte& getCarte(size_t i) const {
            if (i >= 81) throw SetException("Carte invalide");
            return *cartes[i];
        }

        // Interdiction du constructeur par recopie et de l'opérateur d'affectation
        // Note : on pourrait également les passer en privé au lieu d'utiliser le mot clé delete
        // mais cela autoriserait leur utilisation au sein de la classe
        Jeu(const Jeu&) = delete;
        Jeu& operator=(const Jeu& j) = delete;

    };


    class Pioche {
    private:
        // Tableau dynamique contenant les cartes de la pioche
        // La taille dépend du jeu de cartes utilisé
        const Carte** cartes = nullptr;
        // Nombre de cartes restantes dans la pioche
        size_t nb = 0;
    public:
        // Constructeur d'une pioche à partir d'un jeu de cartes
        // On utilise le mot clé "explicit" pour interdire la conversion implicite de Jeu en Pioche
        /* Exercice 22 */
        explicit Pioche(const Jeu&);
        // Destructeur
        ~Pioche();

        bool estVide() const { return nb == 0; }
        size_t getNbCartes() const { return nb; }

        // Choisit une Carte de la Pioche, la supprime de la Pioche et la retourne
        const Carte& piocher();

        // Interdiction du constructeur par recopie et de l'opérateur d'affectation
        Pioche(const Pioche&) = delete;
        Pioche& operator=(const Pioche&) = delete;
    };

    class Plateau {
    private:
        // Tableau dynamique dépendant du nombre de cartes sur le plateau
        // On augmentera la taille du tableau en fonction des besoins
        const Carte** cartes = nullptr;
        size_t nbMax = 0; // taille du tableau allouée
        size_t nb = 0; // taille du tableau utilisée

    public:
        // Le constructeur par défaut convient : il n'y a pas de carte initialement
        Plateau() = default;
        // Destructeur : libère l'espace mémoire utilisé par le tableau de cartes
        ~Plateau() { delete[] cartes;}

        size_t getNbCartes() const { return nb; }

        // Ajoute une carte au plateau
        void ajouter(const Carte& c);
        // Retire une carte du plateau
        void retirer(const Carte& c);

        // Méthode d'affichage du plateau sur un flux ostream
        void print(ostream& f = cout) const;

        // Surcharge du constructeur par recopie et de l'opérateur d'affectation
        Plateau(const Plateau&);
        Plateau& operator=(const Plateau& p);
    };


    class Combinaison {
    private:
        const Carte* c1;
        const Carte* c2;
        const Carte* c3;
    public:
        Combinaison(const Carte& u, const Carte& d, const Carte& t) : c1(&u), c2(&d), c3(&t) {}
        // Important : ne pas oublier de préciser que les accesseurs en lecture sont des méthodes CONST
        const Carte& getCarte1() const { return *c1; }
        const Carte& getCarte2() const { return *c2; }
        const Carte& getCarte3() const { return *c3; }

        bool estUnSet() const;

        // Pas besoin de destructeur car pas de mémoire à libérer
        ~Combinaison() = default;
        // Le constructeur de recopie et l'opérateur d'affectation par défaut suffisent
        // car on copie des valeurs de pointeurs (des adresses)
        Combinaison(const Combinaison& c) = default;
        Combinaison& operator=(const Combinaison& c) = default;
    };


    class Controleur {
    private:
        // Les attributs jeu et plateau seront crées automatiquement à la création d'un objet Controleur
        // en appelant leur constructeur par défaut ; ils seront détruits automatiquement également
        // lorsque l'objet Controleur sera détruit.
        // La pioche est créée dynamiquement et doit être désallouée dans le destructeur de Controleur.
        Jeu jeu;
        Pioche* pioche;
        Plateau plateau;
    public:
        Controleur();
        ~Controleur() { delete pioche; }

        void distribuer();

        // Accesseur en lecture du plateau
        const Plateau& getPlateau() const { return plateau; }
    };



    // Surcharge des opérateurs "<<" pour afficher sur un flux ostream
    ostream& operator<<(ostream& f, const Set::Carte& c);
    ostream& operator<<(ostream& f, const Set::Plateau& p);
    ostream& operator<<(ostream& f, const Set::Combinaison& c);
}


#endif //SCHOTTEN_TOTTEN_SET_H
