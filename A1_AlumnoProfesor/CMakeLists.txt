cmake_minimum_required(VERSION 4.3)
project(A1_AlumnoProfesor)

set(CMAKE_CXX_STANDARD 20)

add_executable(A1_AlumnoProfesor main.cpp
        Alumno.cpp
        Alumno.h
        Profesor.cpp
        Profesor.h
        funciones.cpp
        funciones.h
)
