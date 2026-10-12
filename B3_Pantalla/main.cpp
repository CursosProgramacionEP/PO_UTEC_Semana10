#include <iostream>

#include "Pantalla.h"
using namespace std;

int main() {
    Pantalla pantalla(10, 6);
    pantalla.imprimir();

    char seguir;
    do {
        int x, y;
        cout << "Ingresar coordenadas" << endl;
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;

        pantalla.on(x, y);
        pantalla.imprimir();

        cout << "¿Encender una casilla más? [s/n]: ";
        cin >> seguir;
    } while (seguir == 's' || seguir == 'S');

    return 0;
}
