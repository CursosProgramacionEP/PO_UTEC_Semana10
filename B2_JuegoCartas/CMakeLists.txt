cmake_minimum_required(VERSION 4.3)
project(B2_JuegoCartas)

set(CMAKE_CXX_STANDARD 20)

add_executable(B2_JuegoCartas main.cpp
        Carta.cpp
        Carta.h
        funciones.cpp
        funciones.h
)
