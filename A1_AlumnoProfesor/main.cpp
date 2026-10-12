#include <iostream>

#include "funciones.h"
using namespace std;

int main() {
    cout << "=== Parte 1: objetos por valor ===" << endl;
    {
        Alumno alumno("John", "Doe", 18);
        Profesor profesor("Jesús", "Maestro", 58);

        imprimir_datos_basicos(alumno);
        imprimir_datos_basicos(profesor);
    }

    cout << "=== Parte 2: objetos por puntero ===" << endl;
    {
        Alumno alumno("John", "Doe", 18);
        Profesor profesor("Jesús", "Maestro", 58);

        imprimir_datos_basicos(&alumno);
        imprimir_datos_basicos(&profesor);
    }

    cout << "=== Parte 3: objetos dinamicos ===" << endl;
    Alumno* ptr_alumno = new Alumno("John", "Doe", 18);
    Profesor* ptr_profesor = new Profesor("Jesús", "Maestro", 58);

    imprimir_datos_basicos(ptr_alumno);
    imprimir_datos_basicos(ptr_profesor);

    delete ptr_alumno;
    delete ptr_profesor;

    return 0;
}
