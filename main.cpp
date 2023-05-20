#include <iostream>
#include "Carte.h"
#include "Jeu.h"
using namespace std;
int main() {
    cout << "Hi" << endl;
    string mode_jeu = "Schotten Totten";
    string variante = "tactique";
    int choix_jeu, choix_variante;
    Jeu* j;
    /*
    cout << "Mode de jeu : " << endl;
    getline(cin, mode_jeu);

    cout << "Edition de jeu : " << endl;
    getline(cin, variante);
    cout << mode_jeu << " " << variante << endl;
    */
    //cout << "jeu pas encore instancie" << endl;
    cout << "Bienvenue dans : " << endl;
    cout << "   _____      _           _   _               _______    _   _             \n"
            "  / ____|    | |         | | | |             |__   __|  | | | |            \n"
            " | (___   ___| |__   ___ | |_| |_ ___ _ __      | | ___ | |_| |_ ___ _ __  \n"
            "  \\___ \\ / __| '_ \\ / _ \\| __| __/ _ \\ '_ \\     | |/ _ \\| __| __/ _ \\ '_ \\ \n"
            "  ____) | (__| | | | (_) | |_| ||  __/ | | |    | | (_) | |_| ||  __/ | | |\n"
            " |_____/ \\___|_| |_|\\___/ \\__|\\__\\___|_| |_|    |_|\\___/ \\__|\\__\\___|_| |_|\n"
            "                                                                           \n"
            "                                                                           " << endl;
    /*cout << "Mode de jeu : " << endl;
    getline(cin, mode_jeu);

    cout << "Edition de jeu : " << endl;
    getline(cin, variante);
    cout << mode_jeu << " " << variante << endl;
    */
    cout << "Choisissez le jeu : " << endl;
    cout << "1. Pour Schotten Totten" << endl;
    cout << "2. Pour Schotten Totten 2" << endl;
    cin >> choix_jeu;

    if (choix_jeu == 1) {
        cout << "Schotten Totten selectionne" << endl;
        cout << "Choisissez la variante" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Tactique" << endl;

        cin >> choix_variante;

        if (choix_variante == 1) {
            j = new Jeu("Schotten Totten", "normal");
        }
        else if (choix_variante == 2) {
            j = new Jeu("Schotten Totten", "tactique");
        }
    }

    else {
        cout << "Jeu pas encore implémentée" << endl;
        return 0;
    }




    cout << "nb parties" << j->getNbParties() << endl;
    cout << "nb parties jouees " << j->getNbPartiesJouees() << endl;

    while (j->getNbPartiesJouees() < j->getNbParties()) {
        cout << "jouer" << endl;
        j->jouer_tour();
    }

    cout << "A bientôt dans : " << endl;
    cout << "   _____      _           _   _               _______    _   _             \n"
            "  / ____|    | |         | | | |             |__   __|  | | | |            \n"
            " | (___   ___| |__   ___ | |_| |_ ___ _ __      | | ___ | |_| |_ ___ _ __  \n"
            "  \\___ \\ / __| '_ \\ / _ \\| __| __/ _ \\ '_ \\     | |/ _ \\| __| __/ _ \\ '_ \\ \n"
            "  ____) | (__| | | | (_) | |_| ||  __/ | | |    | | (_) | |_| ||  __/ | | |\n"
            " |_____/ \\___|_| |_|\\___/ \\__|\\__\\___|_| |_|    |_|\\___/ \\__|\\__\\___|_| |_|\n"
            "                                                                           \n"
            "                                                                           " << endl;
    return 0;
}
