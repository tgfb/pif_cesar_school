#include <stdio.h>

int main() {
    // Declaração de um array de 5 elementos inteiros
    int vetor[5] = {10, 20, 30, 40, 50};

    // Acessando e imprimindo cada elemento do array
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, vetor[i]);
    }

    return 0;
}
