#ifndef B2_JUEGOCARTAS_FUNCIONES_H
#define B2_JUEGOCARTAS_FUNCIONES_H

#include "Carta.h"

const int TOTAL = 52;

void crear_mazo(Carta* mazo[]);
void mezclar_mazo(Carta* mazo[]);
void mostrar_mazo(Carta* mazo[]);
void liberar_mazo(Carta* mazo[]);

#endif //B2_JUEGOCARTAS_FUNCIONES_H
