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
    Jeu j(mode_jeu, variante);
    while (j.getNbParties() < j.getNbPartiesJouees()) {
        cout << "jouer" << endl;
        j.jouer_tour();
    }
    return 0;
}
