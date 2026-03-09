#include <stdio.h>

int main() {

    int v[5] = {5, 10, 15, 20, 25};

    int *p;

    // p começa apontando para o primeiro elemento do vetor
    for (p = v; p < v + 5; p++) {

        // *p acessa o valor armazenado no endereço atual
        printf("%d\n", *p);

        // p++ faz o ponteiro avançar para o próximo inteiro na memória
        // o compilador já sabe o tamanho do tipo (int)
    }

    return 0;
}