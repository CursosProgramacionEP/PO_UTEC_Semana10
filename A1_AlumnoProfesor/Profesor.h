//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#ifndef A1_ALUMNOPROFESOR_PROFESOR_H
#define A1_ALUMNOPROFESOR_PROFESOR_H
#include <string>


class Profesor {
private:
    std::string nombre;
    std::string apellidos;
    int edad;
    int horas_dictando;
public:
    Profesor();
    Profesor(const std::string& nombre, const std::string& apellidos, int edad);
    Profesor(const std::string& nombre, const std::string& apellidos, int edad, int horas_dictando);
    ~Profesor();
    void set_nombre(const std::string& nombre);
    void set_apellidos(const std::string& apellidos);
    void set_edad(int edad);
    void set_horas_dictando(int horas_dictando);
    std::string get_nombre() const;
    std::string get_apellidos() const;
    int get_edad() const;
    int get_horas_dictando() const;
};


#endif //A1_ALUMNOPROFESOR_PROFESOR_H
