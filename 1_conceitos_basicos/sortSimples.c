#include <stdio.h>

int main() {
    // Variáveis para guardar os valores lidos
    int a, b, c;
    
    // Variáveis auxiliares para ordenação
    int x, y, z;

    // Leitura dos três valores inteiros
    scanf("%d %d %d", &a, &b, &c);

    // Copiando os valores para outras variáveis
    x = a;
    y = b;
    z = c;

    // Ordenação em ordem crescente usando trocas simples
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    if (x > z) {
        int temp = x;
        x = z;
        z = temp;
    }

    if (y > z) {
        int temp = y;
        y = z;
        z = temp;
    }

    // Impressão dos valores ordenados
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);

    // Linha em branco
    printf("\n");

    // Impressão dos valores na ordem original
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);

    return 0;
}
