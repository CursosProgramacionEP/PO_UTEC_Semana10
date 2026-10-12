//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#include "Profesor.h"
#include <iostream>

using namespace std;

Profesor::Profesor() {
    nombre = "";
    apellidos = "";
    edad = 0;
    horas_dictando = 0;
}

Profesor::Profesor(const string& nombre, const string& apellidos, int edad) {
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->edad = edad;
    this->horas_dictando = 0;
}

Profesor::Profesor(const string& nombre, const string& apellidos, int edad, int horas_dictando) {
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->edad = edad;
    this->horas_dictando = horas_dictando;
}

Profesor::~Profesor() {
    cout << "Eliminándose objeto de la clase Profesor: " << nombre << endl;
}

void Profesor::set_nombre(const string& nombre) { this->nombre = nombre; }
void Profesor::set_apellidos(const string& apellidos) { this->apellidos = apellidos; }
void Profesor::set_edad(int edad) { this->edad = edad; }
void Profesor::set_horas_dictando(int horas_dictando) { this->horas_dictando = horas_dictando; }

string Profesor::get_nombre() const { return nombre; }
string Profesor::get_apellidos() const { return apellidos; }
int Profesor::get_edad() const { return edad; }
int Profesor::get_horas_dictando() const { return horas_dictando; }
