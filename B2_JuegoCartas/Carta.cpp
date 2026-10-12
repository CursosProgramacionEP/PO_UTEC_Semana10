//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#include "Carta.h"
#include <iostream>

using namespace std;

Carta::Carta(int numero, const string& palo) {
    this->numero = numero;
    this->palo = palo;
}

Carta::~Carta() {
}

void Carta::set_numero(int numero) { this->numero = numero; }
void Carta::set_palo(const string& palo) { this->palo = palo; }
int Carta::get_numero() const { return numero; }
string Carta::get_palo() const { return palo; }

void Carta::imprimir() const {
    if (palo == "picas") {
        cout << "♠";
    } else if (palo == "treboles") {
        cout << "♣";
    } else if (palo == "corazones") {
        cout << "♥";
    } else {
        cout << "♦";
    }

    if (numero == 1) {
        cout << "A";
    } else if (numero == 11) {
        cout << "J";
    } else if (numero == 12) {
        cout << "Q";
    } else if (numero == 13) {
        cout << "K";
    } else {
        cout << numero;
    }
}
