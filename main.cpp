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
    Jeu j(mode_jeu, variante);
    cout << "There" << endl;
    cout << "nb parties" << j.getNbParties() << endl;
    cout << "nb parties jouees " << j.getNbPartiesJouees() << endl;

    while (j.getNbPartiesJouees() < j.getNbParties()) {
        cout << "jouer" << endl;
        j.jouer_tour();
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
