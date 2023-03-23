#include <iostream>
#include "Carte.h"

using namespace std;
int main() {
    cout << "Hi" << endl;
    Carte_clan Test("Test", Couleur::Rouge, 2);
    cout << Test.get_force()<< endl;
    cout << static_cast<bool>(Test.get_couleur()) << endl;
    return 0;
}
