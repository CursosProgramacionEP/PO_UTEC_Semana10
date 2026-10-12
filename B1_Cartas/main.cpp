#include <iostream>

#include "Carta.h"
using namespace std;

int main() {
    Carta c1(1, "picas");
    Carta c2(10, "corazones");
    Carta c3(12, "diamantes");
    Carta* c4 = new Carta(13, "treboles");

    c1.imprimir(); cout << "  ";
    c2.imprimir(); cout << "  ";
    c3.imprimir(); cout << "  ";
    c4->imprimir(); cout << endl;

    delete c4;
    return 0;
}
