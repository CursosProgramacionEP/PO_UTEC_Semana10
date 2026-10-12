//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#ifndef B1_CARTAS_CARTA_H
#define B1_CARTAS_CARTA_H
#include <string>


class Carta {
private:
    int numero;
    std::string palo;
public:
    Carta(int numero, const std::string& palo);
    ~Carta();
    void set_numero(int numero);
    void set_palo(const std::string& palo);
    int get_numero() const;
    std::string get_palo() const;
    void imprimir() const;
};


#endif //B1_CARTAS_CARTA_H
