#include <iostream>
#include "Carte.h"
#include "Jeu.h"
using namespace std;
int main() {
    cout << "Hi" << endl;
    string mode_jeu = "Schotten Totten";
    string variante = "normal";
    /*
    cout << "Mode de jeu : " << endl;
    getline(cin, mode_jeu);

    cout << "Edition de jeu : " << endl;
    getline(cin, variante);
    cout << mode_jeu << " " << variante << endl;
    */
    cout << "jeu pas encore instancie" << endl;
    Jeu j(mode_jeu, variante);
    cout << "There" << endl;
    cout << "nb parties" << j.getNbParties() << endl;
    cout << "nb parties jouees " << j.getNbPartiesJouees() << endl;
    while (j.getNbPartiesJouees() < j.getNbParties()) {
        cout << "jouer" << endl;
        j.jouer_tour();
    }
    return 0;
}
