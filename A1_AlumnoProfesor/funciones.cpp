//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#include "funciones.h"

#include <iostream>
using namespace std;

void imprimir_datos_basicos(Alumno alumno) {
    cout << "Nombre: " << alumno.get_nombre() << endl;
    cout << "Apellidos: " << alumno.get_apellidos() << endl;
    cout << "Edad: " << alumno.get_edad() << endl;
    cout << endl;
}

void imprimir_datos_basicos(Profesor profesor) {
    cout << "Nombre: " << profesor.get_nombre() << endl;
    cout << "Apellidos: " << profesor.get_apellidos() << endl;
    cout << "Edad: " << profesor.get_edad() << endl;
    cout << endl;
}

void imprimir_datos_basicos(Alumno* alumno) {
    cout << "Nombre: " << alumno->get_nombre() << endl;
    cout << "Apellidos: " << alumno->get_apellidos() << endl;
    cout << "Edad: " << alumno->get_edad() << endl;
    cout << endl;
}

void imprimir_datos_basicos(Profesor* profesor) {
    cout << "Nombre: " << profesor->get_nombre() << endl;
    cout << "Apellidos: " << profesor->get_apellidos() << endl;
    cout << "Edad: " << profesor->get_edad() << endl;
    cout << endl;
}
