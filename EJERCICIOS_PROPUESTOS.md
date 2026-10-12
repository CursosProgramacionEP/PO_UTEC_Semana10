# Ejercicios propuestos – Semana 10 (POO)

Ejercicios adicionales para los alumnos que terminen antes. Solo usan lo visto en la Semana 10: **constructores y destructores, objetos dinámicos (`new` / `delete`), punteros a objetos, arreglos de objetos, arreglos de punteros a objetos y matrices dinámicas** (sin relaciones entre clases ni herencia).

| # | Ejercicio | Tipo | Tiempo aprox. |
|---|-----------|------|---------------|
| 1 | Rastro de vida de un objeto | Nuevo | 10 min |
| 2 | Complejos → arreglo dinámico | Extensión de A2 | 10–15 min |
| 3 | Alumnos → arreglo de punteros | Extensión de A1 | 15–20 min |
| 4 | Cartas → repartir una mano | Extensión de B2 | 15–20 min |
| 5 | Cartas → contar por palo | Extensión de B2 | 10–15 min |
| 6 | Pantalla → línea y rectángulo | Extensión de B3 | 15 min |
| 7 | Pantalla → limpiar e invertir | Extensión de B3 | 10–15 min |
| 8 | Pantalla → punto en movimiento | Reto | 20–25 min |

---

## 1. Rastro de vida de un objeto

**Enunciado.** Cree la clase `Marca` con un atributo `nombre`. Su constructor imprime `Creando X` y su destructor imprime `Destruyendo X`. En el `main` cree:

- un objeto normal `Marca a("a")`,
- un objeto dinámico `Marca* b = new Marca("b")`,
- un arreglo dinámico `Marca* c = new Marca[3]` (agregue un constructor sin parámetros que use el nombre `"c"`),
- libere `b` con `delete` y `c` con `delete[]`.

**Antes de ejecutar**, escriba en papel el orden en que cree que aparecerán los mensajes. Luego compare. Pruebe también qué pasa si se omite el `delete` de `b`.

**Conceptos:** cuándo se llama al destructor, `delete` vs `delete[]`, fuga de memoria.

**Diagrama de clase**

```mermaid
classDiagram
    class Marca {
        -string nombre
        +Marca()
        +Marca(string nombre)
        +~Marca()
    }
```

**Diagrama de flujo – programa principal**

```mermaid
flowchart TD
    A([Inicio]) --> B["Marca a('a')<br/>objeto en el stack"]
    B --> C["b = new Marca('b')<br/>objeto en el heap"]
    C --> D["c = new Marca[3]<br/>arreglo en el heap"]
    D --> E["delete b"]
    E --> F["delete[] c"]
    F --> G([Fin<br/>se destruye a])
```

---

## 2. Complejos → arreglo dinámico

**Enunciado.** Con la clase `Complejo` de A2, pida al usuario un entero `n` y cree un arreglo dinámico de `n` complejos con `new Complejo[n]`. Lea los valores real e imaginario de cada uno con `set_real` y `set_img`, calcule la **suma de todos** con el método `sumar` e imprima el resultado. Libere el arreglo con `delete[]`.

**Conceptos:** arreglo dinámico de objetos, constructor sin parámetros, `delete[]`.

**Diagrama de clase** (sin cambios respecto a A2)

```mermaid
classDiagram
    class Complejo {
        -float real
        -float img
        +Complejo()
        +Complejo(float real, float img)
        +set_real(float real) void
        +set_img(float img) void
        +sumar(Complejo otro) Complejo
        +imprimir() void
    }
```

**Diagrama de flujo – programa principal**

```mermaid
flowchart TD
    A([Inicio]) --> B[/"leer n"/]
    B --> C["numeros = new Complejo[n]<br/>total = Complejo()<br/>i = 0"]
    C --> D{"i < n?"}
    D -- Sí --> E[/"leer real e img"/]
    E --> F["numeros[i].set_real(...)<br/>numeros[i].set_img(...)<br/>total = total.sumar(numeros[i])<br/>i = i + 1"]
    F --> D
    D -- No --> G[/"imprimir total"/]
    G --> H["delete[] numeros"]
    H --> I([Fin])
```

---

## 3. Alumnos → arreglo de punteros

**Enunciado.** Con la clase `Alumno` de A1, cree un arreglo dinámico de punteros `Alumno** alumnos = new Alumno*[n]`. Cada posición debe apuntar a un alumno creado con `new` (pida nombre, apellidos, edad y créditos por teclado). Luego:

- muestre el alumno con **mayor cantidad de créditos**,
- libere la memoria: primero cada alumno con `delete alumnos[i]` y después el arreglo con `delete[] alumnos`.

Observe en la consola los mensajes del destructor: debe aparecer uno por alumno.

**Conceptos:** arreglo de punteros a objetos, liberación en dos pasos, buscar el mayor elemento.

**Diagrama de clase** (sin cambios respecto a A1)

```mermaid
classDiagram
    class Alumno {
        -string nombre
        -string apellidos
        -int edad
        -int creditos
        +Alumno()
        +Alumno(string nombre, string apellidos, int edad, int creditos)
        +~Alumno()
        +get_nombre() string
        +get_creditos() int
    }
```

**Diagrama de flujo – programa principal**

```mermaid
flowchart TD
    A([Inicio]) --> B[/"leer n"/]
    B --> C["alumnos = new Alumno*[n]<br/>i = 0"]
    C --> D{"i < n?"}
    D -- Sí --> E[/"leer datos"/]
    E --> F["alumnos[i] = new Alumno(...)<br/>i = i + 1"]
    F --> D
    D -- No --> G["mayor = alumnos[0]<br/>recorrer y comparar get_creditos()"]
    G --> H[/"mostrar alumno mayor"/]
    H --> I["delete alumnos[i] para cada i"]
    I --> J["delete[] alumnos"]
    J --> K([Fin])
```

---

## 4. Cartas → repartir una mano

**Enunciado.** Continúe el juego de cartas de B2. Después de mezclar el mazo, reparta **5 cartas** a un jugador: declare `Carta* mano[5]` y copie los **punteros** de las primeras 5 posiciones del mazo (no se crean cartas nuevas). Deje esas posiciones del mazo en `nullptr`.

Muestre la mano y el mazo restante. Al final libere las cartas de la mano y las del mazo que no sean `nullptr`.

**Conceptos:** mover punteros entre arreglos sin copiar objetos, `nullptr`, evitar liberar dos veces el mismo objeto.

**Diagrama de clase** (se reutiliza `Carta` de B1)

```mermaid
classDiagram
    class Carta {
        -int numero
        -string palo
        +Carta(int numero, string palo)
        +~Carta()
        +imprimir() void
    }
```

**Diagrama de flujo – programa principal**

```mermaid
flowchart TD
    A([Inicio]) --> B["crear y mezclar mazo[52]"]
    B --> C["i = 0"]
    C --> D{"i < 5?"}
    D -- Sí --> E["mano[i] = mazo[i]<br/>mazo[i] = nullptr<br/>i = i + 1"]
    E --> D
    D -- No --> F[/"mostrar mano"/]
    F --> G[/"mostrar cartas no nulas del mazo"/]
    G --> H["delete de cada carta de mano<br/>delete de cada carta no nula del mazo"]
    H --> I([Fin])
```

---

## 5. Cartas → contar por palo

**Enunciado.** Con la mano de 5 cartas del ejercicio anterior (o con el mazo completo), cuente cuántas cartas hay de cada palo. Implemente una función `contar_palo(Carta* cartas[], int n, string palo)` que reciba el arreglo de punteros y devuelva la cantidad. Muestre el conteo de los cuatro palos.

**Conceptos:** recorrer un arreglo de punteros con `->`, funciones que reciben arreglos de punteros.

**Diagrama de clase** (sin cambios respecto a B1)

```mermaid
classDiagram
    class Carta {
        -int numero
        -string palo
        +get_numero() int
        +get_palo() string
        +imprimir() void
    }
```

**Diagrama de flujo – `contar_palo(cartas, n, palo)`**

```mermaid
flowchart TD
    A([Inicio]) --> B["cuenta = 0<br/>i = 0"]
    B --> C{"i < n?"}
    C -- Sí --> D{"cartas[i]->get_palo() == palo?"}
    D -- Sí --> E["cuenta = cuenta + 1"]
    D -- No --> F
    E --> F["i = i + 1"]
    F --> C
    C -- No --> G[/"retornar cuenta"/]
    G --> H([Fin])
```

---

## 6. Pantalla → línea y rectángulo

**Enunciado.** Con la clase `Pantalla` de B3, agregue dos métodos:

- `linea_horizontal(int y, int x1, int x2)`: enciende los píxeles de la fila `y` entre `x1` y `x2`.
- `rectangulo(int x, int y, int ancho, int alto)`: dibuja solo el **borde** de un rectángulo con esquina superior izquierda en `(x, y)`.

En el `main` dibuje un marco que rodee toda la pantalla y una línea en el centro.

**Conceptos:** recorrer la matriz dinámica, reutilizar `on()` (que ya valida los límites).

**Diagrama de clase**

```mermaid
classDiagram
    class Pantalla {
        -int ancho
        -int alto
        -bool** pixeles
        +Pantalla(int ancho, int alto)
        +~Pantalla()
        +on(int x, int y) void
        +off(int x, int y) void
        +linea_horizontal(int y, int x1, int x2) void
        +rectangulo(int x, int y, int ancho, int alto) void
        +imprimir() void
    }
```

**Diagrama de flujo – `linea_horizontal(y, x1, x2)`**

```mermaid
flowchart TD
    A([Inicio]) --> B["x = x1"]
    B --> C{"x <= x2?"}
    C -- Sí --> D["on(x, y)<br/>x = x + 1"]
    D --> C
    C -- No --> E([Fin])
```

---

## 7. Pantalla → limpiar e invertir

**Enunciado.** Agregue a `Pantalla`:

- `limpiar()`: apaga todos los píxeles.
- `invertir()`: enciende los apagados y apaga los encendidos.
- `contar_encendidos() const`: devuelve cuántos píxeles están encendidos.

En el `main`, encienda algunos píxeles, invierta la pantalla, muestre el conteo y finalmente limpie.

**Conceptos:** doble recorrido de una matriz dinámica, métodos que modifican el estado interno.

**Diagrama de clase**

```mermaid
classDiagram
    class Pantalla {
        -int ancho
        -int alto
        -bool** pixeles
        +Pantalla(int ancho, int alto)
        +~Pantalla()
        +limpiar() void
        +invertir() void
        +contar_encendidos() int
        +imprimir() void
    }
```

**Diagrama de flujo – `invertir()`**

```mermaid
flowchart TD
    A([Inicio]) --> B["i = 0"]
    B --> C{"i < alto?"}
    C -- Sí --> D["j = 0"]
    D --> E{"j < ancho?"}
    E -- Sí --> F["pixeles[i][j] = !pixeles[i][j]<br/>j = j + 1"]
    F --> E
    E -- No --> G["i = i + 1"]
    G --> C
    C -- No --> H([Fin])
```

---

## 8. Pantalla → punto en movimiento (reto)

**Enunciado.** Usando `Pantalla`, simule un punto que se mueve. Parta de la posición `(0, 0)`. En cada turno el programa imprime la pantalla y pide una tecla:

- `d` derecha, `a` izquierda, `w` arriba, `s` abajo, `q` salir.

Antes de mover, apague el píxel actual con `off()`; después de mover, encienda el nuevo con `on()`. El punto no puede salir de la pantalla (use `get_ancho()` y `get_alto()`).

Variante: deje un rastro, es decir, no apague el píxel anterior.

**Conceptos:** uso combinado de `on` / `off`, getters para validar límites, menú con bucle.

**Diagrama de clase** (sin cambios respecto a B3)

```mermaid
classDiagram
    class Pantalla {
        -int ancho
        -int alto
        -bool** pixeles
        +get_ancho() int
        +get_alto() int
        +on(int x, int y) void
        +off(int x, int y) void
        +imprimir() void
    }
```

**Diagrama de flujo – programa principal**

```mermaid
flowchart TD
    A([Inicio]) --> B["crear pantalla<br/>x = 0, y = 0<br/>on(x, y)"]
    B --> C[/"imprimir pantalla y leer tecla"/]
    C --> D{"tecla == q?"}
    D -- Sí --> K([Fin])
    D -- No --> E["off(x, y)"]
    E --> F["calcular nueva (x, y)<br/>según la tecla"]
    F --> G{"dentro de la pantalla?"}
    G -- No --> H["restaurar (x, y) anterior"]
    G -- Sí --> I
    H --> I["on(x, y)"]
    I --> C
```
