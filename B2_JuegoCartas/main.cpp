#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Carta.h"
#include "funciones.h"
using namespace std;

int main() {
    srand(time(nullptr));

    Carta* mazo[TOTAL];

    crear_mazo(mazo);
    cout << "Mazo ordenado:" << endl;
    mostrar_mazo(mazo);

    mezclar_mazo(mazo);
    cout << endl << "Mazo mezclado:" << endl;
    mostrar_mazo(mazo);

    liberar_mazo(mazo);
    return 0;
}
