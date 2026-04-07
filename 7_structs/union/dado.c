#include <stdio.h>

enum Tipo {
    INT,
    FLOAT
};

union Dado{
    int i;
    float f;
};

struct Valor {
    enum Tipo tipo;
    union Dado dado;    
};

int main() {
    struct Valor v;

    // Exemplo 1: armazenar um inteiro
    v.tipo = INT;
    v.dado.i = 42;

    if (v.tipo == INT) {
        printf("O valor inteiro é: %d\n", v.dado.i);
    } else if (v.tipo == FLOAT) {
        printf("O valor float é: %.2f\n", v.dado.f);
    }

    // Exemplo 2: armazenar um float
    v.tipo = FLOAT;
    v.dado.f = 3.14;

    if (v.tipo == INT) {
        printf("O valor inteiro é: %d\n", v.dado.i);
    } else if (v.tipo == FLOAT) {
        printf("O valor float é: %.2f\n", v.dado.f);
    }

    return 0;
}