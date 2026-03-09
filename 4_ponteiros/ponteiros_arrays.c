#include <stdio.h>

int main() {

    int v[5] = {10, 20, 30, 40, 50}; 
    // criação de um array de 5 inteiros

    int *p;

    p = v;  
    // o nome do array (v) já representa o endereço do primeiro elemento
    // portanto v == &v[0]

    printf("Primeiro elemento: %d\n", *p);
    // *p acessa o conteúdo do endereço v[0]

    printf("Segundo elemento: %d\n", *(p + 1));
    // p+1 aponta para o próximo inteiro na memória
    // equivalente a v[1]

    printf("Terceiro elemento: %d\n", *(p + 2));
    // equivalente a v[2]

    return 0;
}