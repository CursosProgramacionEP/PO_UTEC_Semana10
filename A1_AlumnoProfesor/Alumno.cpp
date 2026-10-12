//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#include "Alumno.h"
#include <iostream>

using namespace std;

Alumno::Alumno() {
    nombre = "";
    apellidos = "";
    edad = 0;
    creditos = 0;
}

Alumno::Alumno(const string& nombre, const string& apellidos, int edad) {
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->edad = edad;
    this->creditos = 0;
}

Alumno::Alumno(const string& nombre, const string& apellidos, int edad, int creditos) {
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->edad = edad;
    this->creditos = creditos;
}

Alumno::~Alumno() {
    cout << "Eliminándose objeto de la clase Alumno: " << nombre << endl;
}

void Alumno::set_nombre(const string& nombre) { this->nombre = nombre; }
void Alumno::set_apellidos(const string& apellidos) { this->apellidos = apellidos; }
void Alumno::set_edad(int edad) { this->edad = edad; }
void Alumno::set_creditos(int creditos) { this->creditos = creditos; }

string Alumno::get_nombre() const { return nombre; }
string Alumno::get_apellidos() const { return apellidos; }
int Alumno::get_edad() const { return edad; }
int Alumno::get_creditos() const { return creditos; }
