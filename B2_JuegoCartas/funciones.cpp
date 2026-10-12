//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#include "funciones.h"

#include <iostream>
#include <string>
using namespace std;

void crear_mazo(Carta* mazo[]) {
    string palos[4] = {"picas", "treboles", "corazones", "diamantes"};
    int k = 0;
    for (int p = 0; p < 4; p++) {
        for (int n = 1; n <= 13; n++) {
            mazo[k] = new Carta(n, palos[p]);
            k++;
        }
    }
}

void mezclar_mazo(Carta* mazo[]) {
    for (int i = 0; i < TOTAL; i++) {
        int j = rand() % TOTAL;
        Carta* temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }
}

void mostrar_mazo(Carta* mazo[]) {
    for (int i = 0; i < TOTAL; i++) {
        mazo[i]->imprimir();
        cout << "\t";
        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }
}

void liberar_mazo(Carta* mazo[]) {
    for (int i = 0; i < TOTAL; i++) {
        delete mazo[i];
        mazo[i] = nullptr;
    }
}
