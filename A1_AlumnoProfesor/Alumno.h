//
// Created by Carlos Palomino Vidal on 11/10/26.
//

#ifndef A1_ALUMNOPROFESOR_ALUMNO_H
#define A1_ALUMNOPROFESOR_ALUMNO_H
#include <string>


class Alumno {
private:
    std::string nombre;
    std::string apellidos;
    int edad;
    int creditos;
public:
    Alumno();
    Alumno(const std::string& nombre, const std::string& apellidos, int edad);
    Alumno(const std::string& nombre, const std::string& apellidos, int edad, int creditos);
    ~Alumno();
    void set_nombre(const std::string& nombre);
    void set_apellidos(const std::string& apellidos);
    void set_edad(int edad);
    void set_creditos(int creditos);
    std::string get_nombre() const;
    std::string get_apellidos() const;
    int get_edad() const;
    int get_creditos() const;
};


#endif //A1_ALUMNOPROFESOR_ALUMNO_H
