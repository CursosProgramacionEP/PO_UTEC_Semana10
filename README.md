# PO_UTEC – Semana 10 (POO, parte 2)

Laboratorio de **Programación II (CS6003)**, Unidad 5: POO. Resumen de la teoría de la sesión 9 (*Objetos dinámicos* y *Arreglos de objetos*) y de dónde se usa en cada ejercicio.

## Ejercicios del laboratorio

| Carpeta | Ejercicio | Teoría que usa |
|---------|-----------|----------------|
| `A1_AlumnoProfesor` | Clases Alumno y Profesor, funciones con objetos y punteros | constructores, destructor, objeto estático vs dinámico |
| `A2_Complejos` | Números complejos | clase, constructores, métodos de clase |
| `B1_Cartas` | Clase Carta | clase, constructor, destructor, getters y setters |
| `B2_JuegoCartas` | Mazo de 52 cartas | arreglo de punteros a objetos |
| `B3_Pantalla` | Pantalla de píxeles | matriz dinámica (`bool**`) |

Ejercicios adicionales: [EJERCICIOS_PROPUESTOS.md](EJERCICIOS_PROPUESTOS.md)

---

## 1. Objetos dinámicos

Un objeto **estático** vive en el stack. Un objeto **dinámico** se crea con `new` en el heap y se accede mediante un puntero.

```cpp
CPunto2D p1(5, 2);                 // estático (stack)
CPunto2D* ptrP1 = &p1;             // puntero a un objeto estático

CPunto2D* p2 = new CPunto2D(5, 2); // dinámico (heap)
```

Acceso a los miembros por un puntero:

```cpp
(*p2).x    // equivalente a
p2->x
```

Dentro de un método, `this` es el puntero al objeto que lo invoca (`this->x`).

### Liberación de memoria

Un objeto dinámico no se destruye solo: hay que liberarlo con `delete`. Al hacerlo se ejecuta el destructor.

```cpp
CPunto2D* p1 = new CPunto2D(5, 2);
CPunto2D* p2 = new CPunto2D(10, 6);

delete p1;
delete p2;
```

> Si se olvida el `delete`, el destructor no se ejecuta y la memoria queda sin liberar (**fuga de memoria**).

**Se usa en:** A1 (partes 2 y 3), A2 y B1 (`new` / `delete` de un objeto).

---

## 2. Arreglos de objetos

### Arreglo dinámico de objetos

Se ejecuta el constructor sin parámetros para cada elemento.

```cpp
CPunto2D* puntos = new CPunto2D[5];
puntos[0] = CPunto2D(5, 4);

// o con inicialización
CPunto2D* puntos = new CPunto2D[5]{
    CPunto2D(5, 4), CPunto2D(6, 2), CPunto2D(1, 1),
    CPunto2D(3, 1), CPunto2D(2, 2)
};

cout << puntos[i].getX();
delete[] puntos;
puntos = nullptr;
```

### Arreglo dinámico de punteros dobles (matrices)

Un arreglo de punteros: cada posición apunta a un objeto creado con `new`.

```cpp
CPunto2D** puntos = new CPunto2D*[5];
puntos[0] = new CPunto2D(5, 4);
puntos[1] = new CPunto2D(6, 2);

cout << puntos[i]->getX();

for (int i = 0; i < 5; ++i)
    delete puntos[i];     // 1) cada objeto
delete[] puntos;          // 2) el arreglo de punteros
puntos = nullptr;
```

| Arreglo simple `CPunto2D*` | Arreglo de punteros `CPunto2D**` |
|----------------------------|----------------------------------|
| Los objetos están contiguos | Cada objeto está en su propio bloque |
| Se libera con un solo `delete[]` | Se libera cada objeto y luego el arreglo |
| Mover un objeto implica copiarlo | Se pueden mover o compartir los punteros sin copiar los objetos |

**Ventajas del arreglo de punteros:** reduce la manipulación de objetos existentes, facilita agregar objetos y permite compartir un objeto entre varios arreglos.
**Desventajas:** requiere memoria adicional para los punteros y la liberación es más elaborada.

**Se usa en:** B2 (`Carta* mazo[52]`) y B3 (`bool** pixeles`, matriz dinámica de `alto` filas).

---

## 3. Usando vectores

```cpp
vector<CPunto2D> puntos;      // la liberación es automática
vector<CPunto2D*> puntos;     // hay que hacer delete de cada puntero
```

Con `vector<CPunto2D*>`, cada objeto creado con `new` debe liberarse con `delete`.

---

## Resumen rápido

| Situación | Se crea con | Se libera con |
|-----------|-------------|---------------|
| Objeto dinámico | `new Clase(...)` | `delete p` |
| Arreglo de objetos | `new Clase[n]` | `delete[] arr` |
| Arreglo de punteros | `new Clase*[n]` y `new Clase(...)` por elemento | `delete arr[i]` para cada elemento y luego `delete[] arr` |
| Matriz dinámica | `new bool*[alto]` y `new bool[ancho]` por fila | `delete[] m[i]` para cada fila y luego `delete[] m` |

## Compilación

Cada carpeta es un proyecto CMake independiente (CLion). Ejecute siempre desde el botón ▶ del target del proyecto.
