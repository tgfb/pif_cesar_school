#include <stdio.h>

// função recebe um ponteiro para inteiro
void alterarValor(int *n) {

    // *n acessa o valor guardado no endereço recebido
    *n = 50;

}

int main() {

    int x = 10;

    printf("Antes da funcao: %d\n", x);

    // passamos o endereço de x
    alterarValor(&x);

    printf("Depois da funcao: %d\n", x);

    return 0;
}