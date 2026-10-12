//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#ifndef B3_PANTALLA_PANTALLA_H
#define B3_PANTALLA_PANTALLA_H


class Pantalla {
private:
    int ancho;
    int alto;
    bool** pixeles;
public:
    Pantalla(int ancho, int alto);
    ~Pantalla();
    int get_ancho() const;
    int get_alto() const;
    void on(int x, int y);
    void off(int x, int y);
    void imprimir() const;
};


#endif //B3_PANTALLA_PANTALLA_H
