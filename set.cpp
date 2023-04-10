//
// Created by lucas on 09/04/2023.
//
#include "set.h"

namespace Set {

    std::initializer_list<Couleur> Couleurs = { Couleur::rouge, Couleur::mauve, Couleur::vert };
    std::initializer_list<Nombre> Nombres = { Nombre::un, Nombre::deux, Nombre::trois };
    std::initializer_list<Forme> Formes = { Forme::ovale, Forme::vague, Forme::losange };
    std::initializer_list<Remplissage> Remplissages = { Remplissage::plein, Remplissage::vide, Remplissage::hachure };

    string toString(Couleur c) {
        switch (c) {
            case Couleur::rouge: return "R";
            case Couleur::mauve: return "M";
            case Couleur::vert: return "V";
            default: throw SetException("Couleur inconnue");
        }
    }

    string toString(Nombre v) {
        switch (v) {
            case Nombre::un: return "1";
            case Nombre::deux: return "2";
            case Nombre::trois: return "3";
            default: throw SetException("Nombre inconnue");
        }
    }

    string toString(Forme f) {
        switch (f) {
            case Forme::ovale: return "O";
            case Forme::vague: return "~";
            case Forme::losange: return "\004";
            default: throw SetException("Forme inconnue");
        }
    }

    string toString(Remplissage r) {
        switch (r) {
            case Remplissage::plein: return "P";
            case Remplissage::vide: return "_";
            case Remplissage::hachure: return "H";
            default: throw SetException("Remplissage inconnu");
        }
    }

    std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
    std::ostream& operator<<(std::ostream& f, Nombre v) {	f << toString(v); return f; }
    std::ostream& operator<<(std::ostream& f, Forme x) { f << toString(x);  return f; }
    std::ostream& operator<<(std::ostream& f, Remplissage r) { f << toString(r); return f; }

    void printCouleurs(std::ostream& f) {
        for (auto c : Couleurs) f << c << " ";
        f << "\n";
    }

    void printNombres(std::ostream& f) {
        for (auto v : Nombres) f << v << " ";
        f << "\n";
    }

    void printFormes(std::ostream& f) {
        for (auto x : Formes) f << x << " ";
        f << "\n";
    }

    void printRemplissages(std::ostream& f) {
        for (auto r : Remplissages) f << r << " ";
        f << "\n";
    }

    /* Début de l'exercice 22 */

    Jeu::Jeu() {
        // On crée dynamiquement l'ensemble des cartes
        size_t i = 0;
        for (auto c : Couleurs)
            for (auto n : Nombres)
                for (auto f : Formes)
                    for (auto r : Remplissages) cartes[i++] = new Carte(c, n, f, r);
    }

    Jeu::~Jeu() {
        // Jeu gère le cycle de vie des cartes, il doit les désallouer
        for (size_t i = 0; i < getNbCartes(); i++) delete cartes[i];
    }


    Pioche::Pioche(const Jeu& j) : cartes(new const Carte*[j.getNbCartes()]), nb(j.getNbCartes()) {
        // Ici, on a fait l'allocation du tableau de cartes directement à l'initialisation
        // Attention à bien vérifier que les méthode "getNbCartes()" et "getCarte()" de la classe Jeu
        // sont bien des méthodes const sinon elles ne pourront pas être utilisées par l'objet const Jeu ici !

        // On remplit la pioche avec les cartes du jeu de cartes
        for (size_t i = 0; i < nb; i++) cartes[i] = &j.getCarte(i);
    }


    Pioche::~Pioche() {
        delete[] cartes;
    }

    const Carte& Pioche::piocher() {
        if (estVide()) throw SetException("Pioche vide");
        // On choisit une carte aléatoire
        size_t x = rand() % nb;
        const Carte* c = cartes[x];
        // On décale les cartes restantes
        for (size_t i = x + 1; i < nb; ++i) cartes[i - 1] = cartes[i];
        nb--;
        // On retourne la carte piochée
        return *c;
    }

    void Plateau::ajouter(const Carte& c) {
        // Si le tableau est rempli
        if (nb == nbMax) {
            // Augmenter la taille du tableau cartes
            // On crée un tableau plus grand
            const Carte** newtab = new const Carte * [(nbMax + 1) * 2];
            // On recopie les valeurs dans le nouveau tableau
            for (size_t i = 0; i < nb; i++) newtab[i] = cartes[i];
            // Le nouveau tableau devient le tableau du Plateau
            // On pense à désallouer l'ancien tableau
            auto old = cartes;
            cartes = newtab;
            delete[] old;
            nbMax = (nbMax + 1) * 2;
        }
        // On ajoute la carte
        cartes[nb++] = &c;
    }

    void Plateau::retirer(const Carte& c) {
        // On cherche la carte correspondante sur le plateau
        size_t i = 0;
        while (i < nb && cartes[i] != &c) i++;
        if (i == nb) throw SetException("Carte inexistante");
        // On fait le décalage pour supprimer la carte du plateau
        i++;
        while (i < nb) {
            cartes[i - 1] = cartes[i];
            i++;
        }
        nb--;
    }

    void Plateau::print(ostream& f) const {
        // On souhaite afficher quatre cartes par ligne
        for (size_t i = 0; i < nb; i++) {
            if (i % 4 == 0) f << "\n";
            f << *cartes[i] << " ";
        }
        f << "\n";
    }

    Plateau::Plateau(const Plateau& p) : cartes(new const Carte* [p.nb]), nb(p.getNbCartes()), nbMax(p.getNbCartes()) {
        // La recopie par défaut ne fonctionne pas ici : on partagerait le même tableau de cartes
        // Il faut donc allouer un tableau propre à cette instance de plateau, et copier les cartes
        for (size_t i = 0; i < nb; ++i) cartes[i] = p.cartes[i];
    }

    Plateau& Plateau::operator=(const Plateau& p) {
        // Si on essaie d'affecter un plateau à lui même, ne rien faire
        if (this != &p) {
            // Si le tableau du plateau est trop petit pour recevoir
            // les cartes affectées, on alloue un nouveau tableau
            // Sinon, on utilise le tableau déjà alloué
            if (p.nb > this->nbMax) {
                // On alloue un nouveau tableau
                const Carte** newtab = new const Carte * [p.nb];
                // On copie les valeurs
                for (size_t i = 0; i < p.nb; ++i) newtab[i] = p.cartes[i];
                // On remplace l'ancien tableau par le nouveau
                // Sans oublier de désallouer l'ancien tableau !
                auto old = this->cartes;
                this->cartes = newtab; // le "this->" est optionnel
                this->nb = p.nb;
                this->nbMax = p.nb;
                delete[] old;
            }
            else {
                // On copie les valeurs dans le tableau déjà existant
                for (size_t i = 0; i < p.nb; ++i) this->cartes[i] = p.cartes[i];
                this->nb = p.nb;
            }
        }
        // On renvoie une référence sur le plateau
        return *this;
    }

    bool Combinaison::estUnSet() const {
        // On vérifie si la combinaison des couleurs est bonne
        // Soit les trois cartes ont la même couleur
        // Soit les trois cartes ont une couleur deux à deux différente
        bool c = (c1->getCouleur() == c2->getCouleur() && c2->getCouleur() == c3->getCouleur())
                 || (c1->getCouleur() != c2->getCouleur()
                     && c2->getCouleur() != c3->getCouleur()
                     && c1->getCouleur() != c3->getCouleur());
        // On vérifie la forme
        bool f = (c1->getForme() == c2->getForme() && c2->getForme() == c3->getForme())
                 || (c1->getForme() != c2->getForme()
                     && c2->getForme() != c3->getForme()
                     && c1->getForme() != c3->getForme());
        // On vérifie le remplissage
        bool r = (c1->getRemplissage() == c2->getRemplissage() && c2->getRemplissage() == c3->getRemplissage())
                 || (c1->getRemplissage() != c2->getRemplissage()
                     && c2->getRemplissage() != c3->getRemplissage()
                     && c1->getRemplissage() != c3->getRemplissage());
        // On vérifie le nombre
        bool n = (c1->getNombre() == c2->getNombre() && c2->getNombre() == c3->getNombre())
                 || (c1->getNombre() != c2->getNombre()
                     && c2->getNombre() != c3->getNombre()
                     && c1->getNombre() != c3->getNombre());

        // On retourne true si toutes les caractéristiques conviennent, false sinon
        return c && f && r && n;
    }


    Controleur::Controleur() {
        // On alloue dynamiquement la pioche
        // Les attributs jeu et plateau sont alloués automatiquement à la création de l'objet
        pioche = new Pioche(jeu);
    }

    void Controleur::distribuer() {
        // S'il y a moins de 12 cartes sur le plateau, on le remplit
        if (plateau.getNbCartes() < 12) {
            while (!pioche->estVide() && plateau.getNbCartes() < 12)
                plateau.ajouter(pioche->piocher()); // on ajoute la carte piochée au plateau directement
        }
            // Sinon, on ajoute une seule carte
        else
        if (!pioche->estVide()) plateau.ajouter(pioche->piocher());
    }


    ostream& operator<<(ostream& f, const Set::Carte& c) {
        // On affiche les quatre caractéristiques de la carte
        f << "(" << c.getNombre() << "," << c.getCouleur() << "," << c.getForme()
          << "," << c.getRemplissage() << ")";
        // On retourne le flux pour pouvoir enchainer les affichages
        return f;
    }
    ostream& operator<<(ostream& f, const Set::Plateau& p) {
        // On affiche le plateau en appelant la méthode print
        // Attention, la méthode print doit être déclarée comme méthode const !
        p.print(f);
        // On retourne le flux... blablabla on connait la chanson mais c'est important
        return f;
    }

    ostream& operator<<(ostream& f, const Set::Combinaison& c) {
        f << "[" << c.getCarte1() << "," << c.getCarte2() << "," << c.getCarte3() << "]";
        return f;
    }
}
