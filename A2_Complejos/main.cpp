#include <iostream>

#include "Complejo.h"
using namespace std;

int main() {
    Complejo z1(3, 2);
    Complejo z2(1, -4);
    Complejo z3(5);
    Complejo z4;

    cout << "z1 = "; z1.imprimir();
    cout << "z2 = "; z2.imprimir();
    cout << "z3 = "; z3.imprimir();
    cout << "z4 = "; z4.imprimir();

    Complejo suma = z1.sumar(z2);
    Complejo resta = z1.restar(z2);

    cout << "z1 + z2 = "; suma.imprimir();
    cout << "z1 - z2 = "; resta.imprimir();

    Complejo* p = new Complejo(2.5, 1.5);
    Complejo r = p->sumar(z3);
    cout << "p + z3 = "; r.imprimir();
    delete p;

    return 0;
}
