#include <stdio.h>

union Valor {
    int numero;
    char letra;
};

int main() {
    union Valor v;

    v.numero = 60;
    printf("Numero: %d\n", v.numero); // 60

    v.letra = 'A';
    printf("Letra: %c\n", v.letra); // A

    printf("Numero: %d\n", v.numero); // 65

    return 0;
}