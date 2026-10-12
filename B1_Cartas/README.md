# B1 – Cartas

## Diagrama de clase

```mermaid
classDiagram
    class Carta {
        -int numero
        -string palo
        +Carta(int numero, string palo)
        +~Carta()
        +set_numero(int numero) void
        +set_palo(string palo) void
        +get_numero() int
        +get_palo() string
        +imprimir() void
    }
```

## Símbolos de los palos

| HEX | Símbolo | Palo |
|-----|---------|------|
| 0x2660 | ♠ | picas |
| 0x2663 | ♣ | treboles |
| 0x2665 | ♥ | corazones |
| 0x2666 | ♦ | diamantes |
