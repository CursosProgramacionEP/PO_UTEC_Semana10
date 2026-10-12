# A1 – Alumno y Profesor

## Diagrama de clase

```mermaid
classDiagram
    class Alumno {
        -string nombre
        -string apellidos
        -int edad
        -int creditos
        +Alumno()
        +Alumno(string nombre, string apellidos, int edad)
        +Alumno(string nombre, string apellidos, int edad, int creditos)
        +~Alumno()
        +set_nombre(string nombre) void
        +set_apellidos(string apellidos) void
        +set_edad(int edad) void
        +set_creditos(int creditos) void
        +get_nombre() string
        +get_apellidos() string
        +get_edad() int
        +get_creditos() int
    }
    class Profesor {
        -string nombre
        -string apellidos
        -int edad
        -int horas_dictando
        +Profesor()
        +Profesor(string nombre, string apellidos, int edad)
        +Profesor(string nombre, string apellidos, int edad, int horas_dictando)
        +~Profesor()
        +set_nombre(string nombre) void
        +set_apellidos(string apellidos) void
        +set_edad(int edad) void
        +set_horas_dictando(int horas_dictando) void
        +get_nombre() string
        +get_apellidos() string
        +get_edad() int
        +get_horas_dictando() int
    }
```

## Preguntas de la sesión

| Versión | ¿Cómo se manifiesta el destructor? | ¿Se llama solo 2 veces? | ¿Fuga de memoria? |
|---------|-----------------------------------|-------------------------|-------------------|
| Por valor | Se imprime el mensaje al salir de cada función y al salir del bloque | No: cada llamada por valor crea una copia que también se destruye | No |
| Por puntero (`&objeto`) | Solo al salir del bloque | Sí, 2 veces | No |
| Dinámico (`new`) | Solo cuando se hace `delete` | Sí, pero solo si se hace `delete` | Sí, si se omite `delete` |
