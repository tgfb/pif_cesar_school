#include <stdio.h>

int main() {

    int x = 10;      // variável inteira comum
    int *p;          // declaração de um ponteiro para inteiro
                    // o * indica que p guarda ENDEREÇOS de memória de inteiros

    p = &x;          // & significa "endereço de"
                    // então estamos guardando dentro de p o endereço da variável x

    printf("Valor de x: %d\n", x);
    // imprime o valor armazenado em x

    printf("Endereco de x: %p\n", &x);
    // %p é usado para imprimir endereços de memória
    // aqui mostramos onde x está na memória

    printf("Valor guardado no ponteiro p (endereco): %p\n", p);
    // p guarda exatamente o mesmo endereço de x

    printf("Valor apontado por p: %d\n", *p);
    // *p significa "valor no endereço apontado por p"
    // como p aponta para x, *p mostra o valor de x

    return 0;
}