#include <stdio.h>

union Valor {
    int numero;
    char letra;
};

int main() {
    union Valor v;

    v.numero = 60;
    printf("Numero: %d\n", v.numero);

    v.letra = 'A';
    printf("Letra: %c\n", v.letra);

    printf("Numero: %d\n", v.numero);

    return 0;
}