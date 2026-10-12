//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#ifndef A2_COMPLEJOS_COMPLEJO_H
#define A2_COMPLEJOS_COMPLEJO_H


class Complejo {
private:
    float real;
    float img;
public:
    Complejo();
    Complejo(float real);
    Complejo(float real, float img);
    ~Complejo();
    void set_real(float real);
    void set_img(float img);
    float get_real() const;
    float get_img() const;
    Complejo sumar(const Complejo& otro) const;
    Complejo restar(const Complejo& otro) const;
    void imprimir() const;
};


#endif //A2_COMPLEJOS_COMPLEJO_H
