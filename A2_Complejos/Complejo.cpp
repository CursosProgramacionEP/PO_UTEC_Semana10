//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#include "Complejo.h"
#include <iostream>

using namespace std;

Complejo::Complejo() {
    real = 0;
    img = 0;
}

Complejo::Complejo(float real) {
    this->real = real;
    this->img = 0;
}

Complejo::Complejo(float real, float img) {
    this->real = real;
    this->img = img;
}

Complejo::~Complejo() {
}

void Complejo::set_real(float real) { this->real = real; }
void Complejo::set_img(float img) { this->img = img; }
float Complejo::get_real() const { return real; }
float Complejo::get_img() const { return img; }

// z1 + z2 = (x1 + x2) + (y1 + y2)i
Complejo Complejo::sumar(const Complejo& otro) const {
    return Complejo(real + otro.real, img + otro.img);
}

// z1 - z2 = (x1 - x2) + (y1 - y2)i
Complejo Complejo::restar(const Complejo& otro) const {
    return Complejo(real - otro.real, img - otro.img);
}

void Complejo::imprimir() const {
    if (img >= 0) {
        cout << real << " + " << img << "i" << endl;
    } else {
        cout << real << " - " << -img << "i" << endl;
    }
}
