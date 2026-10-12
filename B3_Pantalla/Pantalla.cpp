//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#include "Pantalla.h"
#include <iostream>

using namespace std;

Pantalla::Pantalla(int ancho, int alto) {
    this->ancho = ancho;
    this->alto = alto;
    pixeles = new bool*[alto];
    for (int i = 0; i < alto; i++) {
        pixeles[i] = new bool[ancho];
        for (int j = 0; j < ancho; j++) {
            pixeles[i][j] = false;
        }
    }
}

Pantalla::~Pantalla() {
    for (int i = 0; i < alto; i++) {
        delete[] pixeles[i];
    }
    delete[] pixeles;
}

int Pantalla::get_ancho() const { return ancho; }
int Pantalla::get_alto() const { return alto; }

// x = columna, y = fila; (0,0) es la esquina superior izquierda
void Pantalla::on(int x, int y) {
    if (x >= 0 && x < ancho && y >= 0 && y < alto) {
        pixeles[y][x] = true;
    }
}

void Pantalla::off(int x, int y) {
    if (x >= 0 && x < ancho && y >= 0 && y < alto) {
        pixeles[y][x] = false;
    }
}

void Pantalla::imprimir() const {
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (pixeles[i][j]) {
                cout << "\U0001F7E9";
            } else {
                cout << "⬛";
            }
        }
        cout << endl;
    }
}
